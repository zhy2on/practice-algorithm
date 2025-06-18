#include <bits/stdc++.h>
using namespace std;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int board[100][100][100];
bool vis[100][100][100];

int N, M, H;
queue<tuple<int, int, int> > q;

void bfs() {
	while (!q.empty()) {
		auto [z, x, y] = q.front();
		q.pop();

		for (int dir = 0; dir < 6; ++dir) {
			int nz = z + dz[dir];
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (vis[nz][nx][ny] || board[nz][nx][ny]) continue;
			q.push({nz, nx, ny});
			board[nz][nx][ny] = board[z][x][y] + 1;
			vis[nz][nx][ny] = 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> H;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) q.push({i, j, k});
			}
		}
	}

	bfs();

	int ans = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				if (board[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				ans = max(ans, board[i][j][k]);
			}
		}
	}
	cout << ans - 1;
}
