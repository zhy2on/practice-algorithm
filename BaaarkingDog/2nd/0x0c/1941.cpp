#include <bits/stdc++.h>
using namespace std;

char student[8][8];
int skip[25], ans;
bool vis[8][8];

queue<pair<int, int> > q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void init_vis() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (skip[i * 5 + j]) continue;
			vis[i][j] = 0;
			if (q.empty()) {
				q.push({i, j});
				vis[i][j] = 1;
			}
		}
	}
}

bool check_around() {
	init_vis();
	int cnt = 0;
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		++cnt;
		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if (skip[nx * 5 + ny] || vis[nx][ny]) continue;
			q.push({nx, ny});
			vis[nx][ny] = 1;
		}
	}
	return cnt == 7;
}

bool check_count() {
	int cnt = 0;
	for (int i = 0; i < 25; ++i) {
		if (skip[i]) continue;
		if (student[i / 5][i % 5] == 'S') ++cnt;
	}
	return cnt >= 4;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) cin >> student[i][j];
	}

	for (int i = 7; i < 25; ++i) skip[i] = 1;
	do {
		if (!check_count()) continue;
		if (!check_around()) continue;
		++ans;
	} while (next_permutation(skip, skip + 25));
	cout << ans;
}

// 25C7 을 하고 과반인지, 인접했는지 확인
