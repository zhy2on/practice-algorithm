#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

char board[1000][1000];
int fdist[1000][1000];
int jdist[1000][1000];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
	int R, C;
	cin >> R >> C;

	for (int i = 0; i < R; ++i) {
		fill(fdist[i], fdist[i] + C, -1);
		fill(jdist[i], jdist[i] + C, -1);
	}

	queue<pair<int, int> > q, q2;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 'F') {
				q.push({i, j});
				fdist[i][j] = 0;
			}
			else if (board[i][j] == 'J') {
				q2.push({i, j});
				jdist[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (fdist[nx][ny] >= 0 || board[nx][ny] == '#') continue;

			fdist[nx][ny] = fdist[cur.X][cur.Y] + 1;
			q.push({nx, ny});
		}
	}

	while (!q2.empty()) {
		pair<int, int> cur = q2.front(); q2.pop();
	
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
				cout << jdist[cur.X][cur.Y] + 1;
				return 0;
			}
			if (jdist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (fdist[nx][ny] != -1 && jdist[cur.X][cur.Y] + 1 >= fdist[nx][ny]) continue;

			jdist[nx][ny] = jdist[cur.X][cur.Y] + 1;
			q2.push({nx, ny});
		}
	}
	cout << "IMPOSSIBLE";
}
