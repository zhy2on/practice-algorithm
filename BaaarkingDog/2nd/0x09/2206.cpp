#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

char board[1000][1000];
int dist[1000][1000][2];

int n, m;

int bfs() {
	queue<tuple<int, int, int> > q;
	q.push({0, 0, 0});
	dist[0][0][0] = dist[0][0][1] = 1;

	while (!q.empty()) {
		auto [x, y, broke] = q.front();
		q.pop();

		if (x == n - 1 && y == m - 1) return dist[x][y][broke];

		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir], ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			// 벽인데 아직 안 부쉈다면
			if (board[nx][ny] && !broke && !dist[nx][ny][1]) {
				dist[nx][ny][1] = dist[x][y][0] + 1;
				q.push({nx, ny, 1});
			}
			// 벽이 아니라면
			if (!board[nx][ny] && !dist[nx][ny][broke]) {
				dist[nx][ny][broke] = dist[x][y][broke] + 1;
				q.push({nx, ny, broke});
			}
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			board[i][j] -= '0';
		}
	}

	cout << bfs();
}
