#include <bits/stdc++.h>
using namespace std;

int t, w, h;
char board[1000][1000];
int distF[1000][1000];	// fire
int distP[1000][1000];	// person

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve() {
	queue<pair<int, int> > fire, person;

	cin >> w >> h;

	// 입력 & 초기화
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> board[i][j];
			distF[i][j] = distP[i][j] = -1;
			if (board[i][j] == '*') {
				fire.push({i, j});
				distF[i][j] = 0;
			} else if (board[i][j] == '@') {
				person.push({i, j});
				distP[i][j] = 0;
			}
		}
	}

	// 불 bfs
	while (!fire.empty()) {
		auto [x, y] = fire.front();
		fire.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir], ny = y + dy[dir];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (distF[nx][ny] != -1 || board[nx][ny] == '#') continue;

			fire.push({nx, ny});
			distF[nx][ny] = distF[x][y] + 1;
		}
	}

	// 사람 bfs
	while (!person.empty()) {
		auto [x, y] = person.front();
		person.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir], ny = y + dy[dir];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
				cout << distP[x][y] + 1 << '\n';
				return;
			}
			if (distP[nx][ny] != -1 || board[nx][ny] == '#') continue;
			if (distF[nx][ny] != -1 && distP[x][y] + 1 >= distF[nx][ny])
				continue;

			person.push({nx, ny});
			distP[nx][ny] = distP[x][y] + 1;
		}
	}
	cout << "IMPOSSIBLE\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) solve();
}
