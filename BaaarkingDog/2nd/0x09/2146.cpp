#include <bits/stdc++.h>
using namespace std;

int n, island = 2, ans = INT_MAX;
int board[100][100], dist[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs() {
	queue<pair<int, int> > q;
	for (int i = 0; i < n; ++i) fill(dist[i], dist[i] + n, -1);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j]) {
				q.push({i, j});
				dist[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] == board[x][y]) continue;

			if (board[nx][ny] && board[nx][ny] != board[x][y]) {
				ans = min(ans, dist[nx][ny] + dist[x][y]);
			}

			if (!board[nx][ny] && dist[nx][ny] == -1) {	 // 바다를 처음 만났다면
				board[nx][ny] = board[x][y];
				dist[nx][ny] = dist[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
}

void mark(int i, int j) {
	queue<pair<int, int> > q;
	q.push({i, j});
	board[i][j] = island;

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] == island || !board[nx][ny]) continue;

			q.push({nx, ny});
			board[nx][ny] = island;
		}
	}
	++island;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cin >> board[i][j];
	}

	// 각 구역을 칠해놓고
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 1) mark(i, j);
		}
	}

	// bfs
	bfs();
	cout << ans;
}
