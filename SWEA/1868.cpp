#include <bits/stdc++.h>
using namespace std;

int N;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

char board[302][302];

void bfs(int tc) {
	bool visit[302][302] = {};
	queue<pair<int, int> > q;

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!board[i][j] && !visit[i][j]) {
				q.push({i, j});
				visit[i][j] = 1;
				++cnt;

				while (!q.empty()) {
					auto [x, y] = q.front();
					q.pop();

					for (int d = 0; d < 8; ++d) {
						int nx = x + dx[d], ny = y + dy[d];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (visit[nx][ny] || board[nx][ny] == -1) continue;
						visit[nx][ny] = 1;
						if (board[nx][ny] == 0) q.push({nx, ny});
					}
				}
			}
		}
	}

	// 방문 못 한 애들을 세줘야 함
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j] != -1 && !visit[i][j]) ++cnt;
		}
	}
	cout << '#' << tc << ' ' << cnt << '\n';
}

void init() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j] == -1) continue;
			for (int d = 0; d < 8; ++d) {
				int r = i + dx[d], c = j + dy[d];
				if (r < 0 || r >= N || c < 0 || c >= N) continue;
				if (board[r][c] == -1) ++board[i][j];
			}
		}
	}
}

void run(int tc) {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
			board[i][j] = board[i][j] == '*' ? -1 : 0;
		}
	}

	init();
	bfs(tc);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) run(tc);
}
