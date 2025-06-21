#include <bits/stdc++.h>
using namespace std;

int T, W, H;
char board[1000][1000];
int dist1[1000][1000];
int dist2[1000][1000];
int ans = INT_MAX;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

queue<tuple<int, int> > q1, q2;

void bfs2() {
	while (!q2.empty()) {
		auto [x, y] = q2.front();
		q2.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
				if (!dist1[x][y] || dist2[x][y] < dist1[x][y])
					ans = min(ans, dist2[x][y]);
				continue;
			}
			if (board[nx][ny] != '.' || dist2[nx][ny]) continue;

			q2.push({nx, ny});
			dist2[nx][ny] = dist2[x][y] + 1;
		}
	}
}

void bfs1() {
	while (!q1.empty()) {
		auto [x, y] = q1.front();
		q1.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (board[nx][ny] != '.' || dist1[nx][ny]) continue;

			q1.push({nx, ny});
			dist1[nx][ny] = dist1[x][y] + 1;
		}
	}
}

void init() {
	for (int i = 0; i < H; ++i) {
		fill(board[i], board[i] + W, 0);
		fill(dist1[i], dist1[i] + W, 0);
		fill(dist2[i], dist2[i] + W, 0);
	}
	ans = INT_MAX;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> W >> H;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				cin >> board[i][j];
				if (board[i][j] == '*') {
					q1.push({i, j});
					dist1[i][j] = 1;
				} else if (board[i][j] == '@') {
					board[i][j] = '.';
					q2.push({i, j});
					dist2[i][j] = 1;
				}
			}
		}
		bfs1();
		bfs2();
		if (ans == INT_MAX)
			cout << "IMPOSSIBLE\n";
		else
			cout << ans << '\n';
		init();
	}
}
