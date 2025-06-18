#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool vis[100][100];
string board[100];

int N, ans1, ans2;

queue<pair<int, int> > q;

int bfs(int x, int y) {
	if (vis[x][y]) return 0;

	q.push({x, y});
	vis[x][y] = 1;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (vis[nx][ny]) continue;
			if (board[cur.X][cur.Y] != board[nx][ny]) continue;

			q.push({nx, ny});
			vis[nx][ny] = 1;
		}
	}
	return 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i) cin >> board[i];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) ans1 += bfs(i, j);
	}

	for (int i = 0; i < N; ++i) fill(vis[i], vis[i] + N, 0);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			if (board[i][j] == 'G') board[i][j] = 'R';
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) ans2 += bfs(i, j);
	}

	cout << ans1 << ' ' << ans2;
}
