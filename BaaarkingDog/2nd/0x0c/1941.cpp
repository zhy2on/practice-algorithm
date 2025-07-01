#include <bits/stdc++.h>
using namespace std;

char student[5][5];
int gang[7], board[5][5], ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool bfs_check(int r, int c) {
	queue<pair<int, int> > q;
	bool vis[5][5] = {};

	q.push({r, c});
	vis[r][c] = 1;
	int cnt = 0;
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		++cnt;

		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if (!board[nx][ny] || vis[nx][ny]) continue;
			q.push({nx, ny});
			vis[nx][ny] = 1;
		}
	}
	return cnt == 7;
}

void dfs(int k, int st, int soms) {
	if (k == 7) {
		if (soms >= 4 && bfs_check(gang[0] / 5, gang[0] % 5)) ++ans;
		return;
	}

	for (int i = st; i < 25; ++i) {
		gang[k] = i;
		board[i / 5][i % 5] = 1;
		// soms += 1 하지 않게 조심
		dfs(k + 1, i + 1, soms + (student[i / 5][i % 5] == 'S'));
		board[i / 5][i % 5] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) cin >> student[i][j];
	}
	dfs(0, 0, 0);
	cout << ans;
}
