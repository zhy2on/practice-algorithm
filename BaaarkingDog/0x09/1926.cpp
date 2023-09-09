#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void) {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	queue<pair<int, int> > Q;
	int start = 0, cnt = 0, width = 0;

	while (1) {
		while (start < m * n) {
			if (board[start / m][start % m] && !vis[start / m][start % m])
				break;
			++start;
		}
		if (start == m * n) break;

		++cnt;
		vis[start / m][start % m] = 1;
		Q.push({start / m, start % m});

		int tmp = 0;
		while (!Q.empty()) {
			pair<int, int> cur = Q.front();
			Q.pop();
			++tmp;

			for (int dir = 0; dir < 4; ++dir) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (vis[nx][ny] || !board[nx][ny]) continue;

				vis[nx][ny] = 1;
				Q.push({nx, ny});
			}
		}
		if (tmp > width) width = tmp;
	}

	cout << cnt << '\n' << width;
}
