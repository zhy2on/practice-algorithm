#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int board[8][8], ans;

int N, M;

int filled_area(int x, int y, int dir) {
	int cnt = 0;
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= N || y < 0 || y >= M) break;
		if (board[x][y] == 6) break;

		if (board[x][y] == 0) ++cnt;
	}
	return cnt;
}

void fill_board(int x, int y, int dir) {
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= N || y < 0 || y >= M) break;
		if (board[x][y] == 6) break;

		if (board[x][y] == 0) board[x][y] = -1;
	}
}

vector<pair<int, int> > area_array(int x, int y) {
	vector<pair<int, int> > area;
	for (int i = 0; i < 4; ++i) area.push_back({filled_area(x, y, i), i});
	return area;
}

void cam5(int x, int y) {
	for (int i = 0; i < 4; ++i) fill_board(x, y, i);
}

void cam4(int x, int y) {
	vector<pair<int, int> > area = area_array(x, y);
	sort(area.begin(), area.end());
	for (int i = 1; i < 4; ++i) fill_board(x, y, area[i].Y);
}

void cam3(int x, int y) {
	vector<pair<int, int> > area = area_array(x, y);
	sort(area.begin(), area.end());
	if ((area[2].X + area[3].X) % 2) {
		fill_board(x, y, area[3].Y);
		fill_board(x, y, area[2].Y);
	} else {
		fill_board(x, y, area[3].Y);
		fill_board(x, y, area[1].Y);
	}
}

void cam2(int x, int y) {
	vector<pair<int, int> > area = area_array(x, y);
	if (area[0].X + area[2].X > area[1].X + area[3].X) {
		fill_board(x, y, area[0].Y);
		fill_board(x, y, area[2].Y);
	} else {
		fill_board(x, y, area[1].Y);
		fill_board(x, y, area[3].Y);
	}
}

void cam1(int x, int y) {
	vector<pair<int, int> > area = area_array(x, y);
	sort(area.begin(), area.end());
	fill_board(x, y, area[3].Y);
}

void switch_cam_case(int x, int y, int cam) {
	switch (cam) {
		case 1:
			cam1(x, y);
			break;
		case 2:
			cam2(x, y);
			break;
		case 3:
			cam3(x, y);
			break;
		case 4:
			cam4(x, y);
			break;
		case 5:
			cam5(x, y);
			break;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];
	}

	for (int k = 5; k >= 1; --k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (board[i][j] == k) switch_cam_case(i, j, k);
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			if (board[i][j] == 0) ++ans;
	}

	if (ans == N * M) ans = 0;
	cout << ans;
}

/*
6 6
0 0 0 0 0 0
0 2 0 0 0 0
0 0 0 0 6 0
0 6 0 0 2 5
0 0 0 0 0 0
0 0 0 0 0 5

6 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 6 0
0 1 0 0 2 0
0 0 0 0 0 0
0 0 0 0 0 5
*/
