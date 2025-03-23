#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

char board[100][100];
bool vis[100][100];
int dist[100][100];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void bfs(int N) {
	queue<pair<int, int> > q;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!vis[i][j]) {
				vis[i][j] = 1;
				q.push({i, j});
			}

			while (!q.empty()) {
				pair<int, int> cur = q.front(); q.pop();

				for (int dir = 0; dir < 4; ++dir) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (vis[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;

					vis[nx][ny] = 1;
					dist[nx][ny] = dist[cur.X][cur.Y] + 1;
					q.push({nx, ny});
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
			dist[i][j] = 0;
		}
	}

	bfs(N);

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!dist[i][j]) ++cnt;
			if (board[i][j] == 'G') board[i][j] = 'R';
			dist[i][j] = 0;
			vis[i][j] = 0;
		}
	}

	cout << cnt << ' ';

	bfs(N);

	cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!dist[i][j]) ++cnt;
		}
	}

	cout << cnt;
}
