#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[100][100][100];
int vis[100][100][100];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dh[2] = {1, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, N, H;

	cin >> M >> N >> H;
	queue<pair<int, pair<int, int> > > q;

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) q.push({i, {j, k}});
			}
		}
	}

	while (!q.empty()) {
		pair<int, pair<int, int> > cur = q.front(); q.pop();

		// 상하좌우
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.Y.X + dx[dir];
			int ny = cur.Y.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (vis[cur.X][nx][ny] || board[cur.X][nx][ny]) continue;

			vis[cur.X][nx][ny] = 1;
			board[cur.X][nx][ny] = board[cur.X][cur.Y.X][cur.Y.Y] + 1;
			q.push({cur.X, {nx, ny}});
		}
		// 윗칸아래칸
		for (int dir = 0; dir < 2; ++dir) {
			int nh = cur.X + dh[dir];
			if (nh < 0 || nh >= H) continue;
			if (vis[nh][cur.Y.X][cur.Y.Y] || board[nh][cur.Y.X][cur.Y.Y]) continue;

			vis[nh][cur.Y.X][cur.Y.Y] = 1;
			board[nh][cur.Y.X][cur.Y.Y] = board[cur.X][cur.Y.X][cur.Y.Y] + 1;
			q.push({nh, {cur.Y.X, cur.Y.Y}});
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
