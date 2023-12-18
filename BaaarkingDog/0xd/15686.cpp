#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N, M, ans = 100;
int board1[50][50], board2[50][50], combi[13];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector<pair<int, int> > chicken, house;

int bfs(int x, int y) {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) board2[i][j] = board1[i][j];
	queue<pair<int, int> > q;
	q.push({x, y});
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (board2[nx][ny] > 0) continue;
			if (board2[nx][ny] == -1) return board2[cur.X][cur.Y] + 1;
			board2[nx][ny] = board2[cur.X][cur.Y] + 1;
			q.push({nx, ny});
		}
	}
	return 0;
}

int chicken_distance() {
	for (int i = 0; i < N; ++i) fill(board1[i], board1[i] + N, 0);
	// 살아남은 치킨집 보드 만들기
	for (int i = 0; i < M; ++i) {
		int idx = combi[i];
		board1[chicken[idx].X][chicken[idx].Y] = -1;
	}

	int d = 0;
	for (int i = 0; i < house.size(); ++i) {
		d += bfs(house[i].X, house[i].Y);
	}
	return d;
}

void dfs(int t, int idx) {
	if (t == M) {
		ans = min(ans, chicken_distance());
		return;
	}
	for (int i = idx; i < chicken.size(); ++i) {
		combi[t] = i;
		dfs(t + 1, i + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int k;
			cin >> k;
			if (k == 1)
				house.push_back({i, j});
			else if (k == 2)
				chicken.push_back({i, j});
		}
	}

	// chicken에서 M개의 치킨 조합을 뽑음
	// house 돌면서 bfs로 치킨거리 구해서 min값 찾기
	dfs(0, 0);
	cout << ans;
}
