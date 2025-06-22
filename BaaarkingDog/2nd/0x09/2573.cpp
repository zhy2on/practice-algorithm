#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
int board[301][301], sea[301][301], vis[301][301];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

queue<pair<int, int> > q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 입력
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];

			// 빙산 count
			if (board[i][j]) ++cnt;
		}
	}

	for (int year = 1;; ++year) {
		// 초기화
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == 0)
					sea[i][j] = 1;
				else
					q.push({i, j});
			}
		}

		// 빙산 녹이기
		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int nx = x + dx[dir], ny = y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (sea[nx][ny] && board[x][y]) {
					--board[x][y];
					if (!board[x][y]) --cnt;
				}
			}
		}

		// 빙산 bfs
		int tmp = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				vis[i][j] = 0;
				if (board[i][j] && q.empty()) {
					q.push({i, j});
					vis[i][j] = 1;
					++tmp;
				}
			}
		}

		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int nx = x + dx[dir], ny = y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (!board[nx][ny] || vis[nx][ny]) continue;

				q.push({nx, ny});
				vis[nx][ny] = 1;
				++tmp;
			}
		}

		// 확인
		if (tmp != cnt) {
			cout << year;
			return 0;
		}
	}
}
