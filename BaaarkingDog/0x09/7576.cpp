#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[1000][1000];
bool vis[1000][1000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n;

	cin >> m >> n;

	queue<pair<int, int> > q;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				vis[i][j] = 1;
				q.push({i, j});
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] == 1 || board[nx][ny] == -1)
				continue;

			vis[nx][ny] = 1;
			q.push({nx, ny});
			board[nx][ny] = board[cur.X][cur.Y] + 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 0) {
				cout << "-1";
				return 0; 
			}
			if (board[i][j] > ans) ans = board[i][j];
		}
	}

	cout << ans - 1;
}
