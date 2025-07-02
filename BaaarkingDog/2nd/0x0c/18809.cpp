#include <bits/stdc++.h>
using namespace std;

int n, m, g, r, y, ans;
int board[52][52], yellow[2510], gr[50];
bool gused[50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs() {
	queue<tuple<int, int, char> > q;
	int dist[52][52] = {};
	char type[52][52] = {};

	for (int i = 0; i < g + r; ++i) {
		int x = gr[i] / m, y = gr[i] % m;
		char color = gused[i] ? 'G' : 'R';
		q.push({x, y, color});
		dist[x][y] = 1;
		type[x][y] = color;
	}

	int flower = 0;
	while (!q.empty()) {
		auto [x, y, c] = q.front();
		q.pop();

		if (type[x][y] == 'F') continue;  // 꽃 피웠으면 퍼지지 않음

		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 0) continue;

			if (dist[nx][ny] == 0) {
				// 아직 방문 안 했으면 퍼짐
				dist[nx][ny] = dist[x][y] + 1;
				type[nx][ny] = c;
				q.push({nx, ny, c});
				continue;
			}
			if (dist[nx][ny] == dist[x][y] + 1 && type[nx][ny] != c &&
				type[nx][ny] != 'F') {
				// 같은 시간에 다른 색 -> 꽃 생성
				type[nx][ny] = 'F';
				flower++;
			}
		}
	}
	ans = max(ans, flower);
}

void grCg(int k, int st) {
	if (k == g) {
		bfs();
		return;
	}

	for (int i = st; i < g + r; ++i) {
		gused[i] = 1;
		grCg(k + 1, i + 1);
		gused[i] = 0;
	}
}

void yCgr(int k, int st) {
	if (k == g + r) {
		grCg(0, 0);
		return;
	}
	for (int i = st; i < y; ++i) {
		gr[k] = yellow[i];
		yCgr(k + 1, i + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 2) yellow[y++] = i * m + j;
		}
	}
	yCgr(0, 0);
	cout << ans;
}

// yellow 중 g+r 만큼 뽑고
// g+r 중 g 만큼 뽑음
// bfs로 검사
