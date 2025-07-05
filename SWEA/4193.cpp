#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int tc, int board[20][20], int dist[20][20], pair<int, int> start,
		 pair<int, int> goal) {
	queue<tuple<int, int, int> > q;

	q.push({start.X, start.Y, 0});
	dist[start.X][start.Y] = 0;

	while (!q.empty()) {
		auto [x, y, t] = q.front();
		q.pop();

		if (x == goal.X && y == goal.Y) break;

		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (board[nx][ny] == 1 || dist[nx][ny] != -1) continue;

			if (board[nx][ny] == 0) {
				q.push({nx, ny, t + 1});
				dist[nx][ny] = t + 1;
				continue;
			}
			if ((t + 1) % 3 == 0) {
				dist[nx][ny] = t + 1;
				q.push({nx, ny, t + 1});
				continue;
			}
			q.push({x, y, t + 1});
		}
	}
	cout << '#' << tc << ' ' << dist[goal.X][goal.Y] << '\n';
}

void run(int t) {
	int board[20][20] = {};
	int dist[20][20] = {};
	pair<int, int> start, goal;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
			dist[i][j] = -1;
		}
	}

	cin >> start.X >> start.Y >> goal.X >> goal.Y;

	bfs(t, board, dist, start, goal);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) run(t);
}
