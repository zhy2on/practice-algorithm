#include <bits/stdc++.h>
using namespace std;

pair<int, int> chicken[13];
int chosen[13], board[50][50];
int N, M, c_num, ans = INT_MAX;

int dist(int i, int j) {
	int d = INT_MAX;
	for (int k = 0; k < M; ++k) {
		auto [x, y] = chicken[chosen[k]];
		d = min(d, abs(x - i) + abs(y - j));
	}
	return d;
}

void dfs(int k, int st) {
	if (k == M) {
		int d = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (board[i][j] == 1) d += dist(i, j);
			}
		}
		ans = min(ans, d);
		return;
	}

	for (int i = st; i < c_num; ++i) {
		chosen[k] = i;
		dfs(k + 1, i + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 2) chicken[c_num++] = {i, j};
		}
	}
	dfs(0, 0);
	cout << ans;
}
