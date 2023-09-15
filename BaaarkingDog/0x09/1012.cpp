#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[50][50];
bool vis[50][50];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	int M, N, K;

	cin >> T;

	while (T--) {
		cin >> M >> N >> K;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				board[i][j] = 0;
				vis[i][j] = 0;
			}
		}

		while (K--) {
			int i, j;
			cin >> j >> i;
			board[i][j] = 1;
		}

		queue<pair<int, int> > q;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (board[i][j] == 1) {
					vis[i][j] = 1;
					q.push({i, j});
				}

				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; ++dir) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						if (vis[nx][ny] || !board[nx][ny]) continue;

						vis[nx][ny] = 1;
						board[nx][ny] = board[cur.X][cur.Y] + 1;
						q.push({nx, ny});
					}
				}
			}
		}


		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (board[i][j] == 1) ++cnt;
			}
		}

		cout << cnt << '\n';
	}
}
