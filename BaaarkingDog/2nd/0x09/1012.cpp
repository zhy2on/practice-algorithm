#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[51][51];
bool vis[51][51];
int M, N, K;

queue<pair<int, int> > q;

void bfs(int x, int y) {
	vis[x][y] = 1;
	q.push({x, y});

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (!board[nx][ny] || vis[nx][ny]) continue;

			vis[nx][ny] = 1;
			q.push({nx, ny});
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> M >> N >> K;

		for (int k = 0; k < K; ++k) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}

		int ans = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (board[i][j] && !vis[i][j]) {
					bfs(i, j);
					++ans;
				}
			}
		}

		cout << ans << '\n';

		for (int i = 0; i < N; ++i) {
			fill(board[i], board[i] + M, 0);
			fill(vis[i], vis[i] + M, 0);
		}
	}
}
