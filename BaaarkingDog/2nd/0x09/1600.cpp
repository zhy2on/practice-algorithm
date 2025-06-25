#include <bits/stdc++.h>
using namespace std;

int K, W, H;
int board[200][200];
int dist[200][200][31];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int hdx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int hdy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

queue<tuple<int, int, int> > q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> W >> H;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> board[i][j];
			for (int k = 0; k <= K; ++k) dist[i][j][k] = -1;
		}
	}

	q.push({0, 0, 0});
	dist[0][0][0] = 0;

	while (!q.empty()) {
		auto [x, y, cnt] = q.front();
		q.pop();

		if (x == H - 1 && y == W - 1) {
			cout << dist[x][y][cnt];
			return 0;
		}

		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (board[nx][ny] || dist[nx][ny][cnt] != -1) continue;

			q.push({nx, ny, cnt});
			dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
		}

		if (cnt == K) continue;

		for (int d = 0; d < 8; ++d) {
			int nx = x + hdx[d], ny = y + hdy[d];
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (board[nx][ny] || dist[nx][ny][cnt + 1] != -1) continue;

			q.push({nx, ny, cnt + 1});
			dist[nx][ny][cnt + 1] = dist[x][y][cnt] + 1;
		}
	}

	cout << -1;
}
