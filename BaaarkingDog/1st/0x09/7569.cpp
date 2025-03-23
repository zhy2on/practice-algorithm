#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int board[100][100][100];
int vis[100][100][100];

int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, N, H;

	cin >> M >> N >> H;
	queue<tuple<int, int, int> > q;

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) q.push({i, j, k});
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		int curZ, curX, curY;
		tie(curZ, curX, curY) = cur;

		for (int dir = 0; dir < 6; ++dir) {
			int nz = curZ + dz[dir];
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
			if (vis[nz][nx][ny] || board[nz][nx][ny]) continue;

			vis[nz][nx][ny] = 1;
			board[nz][nx][ny] = board[curZ][curX][curY] + 1;
			q.push({nz, nx, ny});
		}
	}

	int cnt = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				if (!board[i][j][k]) {
					cout << "-1";
					return 0;
				}
				cnt = max(cnt, board[i][j][k]);
			}
		}
	}
	if (cnt == 1) cout << '0';
	else cout << cnt - 1;
}
