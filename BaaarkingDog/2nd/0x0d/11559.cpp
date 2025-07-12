#include <bits/stdc++.h>
using namespace std;

char board[12][6];
queue<pair<int, int> > q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int ans;

void fall() {
	for (int i = 10; i >= 0; --i) {
		for (int j = 0; j < 6; ++j) {
			if (board[i][j] != '.') {
				int f = i;
				while (1) {
					if (f == 11) break;
					if (board[f + 1][j] != '.') break;
					++f;
				}
				swap(board[i][j], board[f][j]);
			}
		}
	}
}

bool bfs(int i, int j) {
	bool visit[12][6] = {};
	int area = 0;

	q.push({i, j});
	visit[i][j] = 1;
	++area;

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
			if (visit[nx][ny] || board[nx][ny] != board[i][j]) continue;
			q.push({nx, ny});
			visit[nx][ny] = 1;
			++area;
		}
	}

	if (area >= 4) {
		for (int i = 0; i < 12; ++i) {
			for (int j = 0; j < 6; ++j) {
				if (visit[i][j]) board[i][j] = '.';
			}
		}
		return true;
	}
	return false;
}

bool bomb() {
	bool flag = 0;
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (board[i][j] != '.') {
				if (bfs(i, j)) flag = 1;
			}
		}
	}
	return flag;
}

void run() {
	while (1) {
		if (!bomb()) return;
		fall();
		++ans;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j) cin >> board[i][j];
	}
	run();
	cout << ans;
}
