#include <iostream>
#include <vector>

using namespace std;

#define X first
#define Y second

int N, M, board1[10][10], board2[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector<pair<int, int> > cctv;

int fill_area(int x, int y, int dir) {
	dir %= 4;
	int cnt = 0;
	while (1) {
		x = x + dx[dir];
		y = y + dy[dir];

		if (x < 0 || x >= N || y < 0 || y >= M) break;
		if (board2[x][y] == 6) break;
		if (board2[x][y] == 0 && ++cnt) board2[x][y] = -1;
	}
	return cnt;
}

int cctv_area(int x, int y, int dir) {
	int area = 0;
	switch (board1[x][y]) {
		case 1:
			area += fill_area(x, y, dir);
			break;
		case 2:
			area += fill_area(x, y, dir);
			area += fill_area(x, y, dir + 2);
			break;
		case 3:
			area += fill_area(x, y, dir);
			area += fill_area(x, y, dir + 1);
			break;
		case 4:
			area += fill_area(x, y, dir);
			area += fill_area(x, y, dir + 2);
			area += fill_area(x, y, dir + 3);
			break;
		case 5:
			area += fill_area(x, y, dir);
			area += fill_area(x, y, dir + 1);
			area += fill_area(x, y, dir + 2);
			area += fill_area(x, y, dir + 3);
			break;
	}
	return area;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int wall = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board1[i][j];
			if (board1[i][j] >= 1 && board1[i][j] <= 5) cctv.push_back({i, j});
			if (board1[i][j] == 6) ++wall;
		}
	}

	int area = 0;
	for (int t = 0; t < (1 << (2 * cctv.size())); ++t) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				board2[i][j] = board1[i][j];

		int tmp = t;
		int cnt = 0;
		for (int i = 0; i < cctv.size(); ++i) {
			int dir = tmp % 4;
			tmp /= 4;
			cnt += cctv_area(cctv[i].X, cctv[i].Y, dir);
		}
		area = max(cnt, area);
	}

	cout << N * M - cctv.size() - wall - area;
}
