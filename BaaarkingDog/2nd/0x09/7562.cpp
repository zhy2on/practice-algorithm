#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

int dist[300][300];
int L;
pair<int, int> start, target;

queue<pair<int, int> > q;

void run() {
	q.push({start.X, start.Y});
	dist[start.X][start.Y] = 0;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 8; ++dir) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= L || ny < 0 || ny >= L) continue;
			if (dist[nx][ny] >= 0) continue;

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			if (nx == cur.X && ny == cur.Y) return;

			q.push({nx, ny});
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;

	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> L;
		for (int i = 0; i < L; ++i) fill(dist[i], dist[i] + L, -1);

		cin >> start.X >> start.Y;
		cin >> target.X >> target.Y;

		run();
		cout << dist[target.X][target.Y] << '\n';
	}
}
