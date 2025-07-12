#include <bits/stdc++.h>
using namespace std;

int N, ans, dir[5];
int board[20][20], board2[20][20];

void rotate() {
	int tmp[20][20] = {};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			tmp[j][N - 1 - i] = board2[i][j];
		}
	}
	memcpy(board2, tmp, sizeof tmp);
}

void swipe() {
	for (int i = 0; i < N; ++i) {
		int idx = 0;
		int tmp[20] = {};
		for (int j = 0; j < N; ++j) {
			if (!board2[i][j]) continue;
			if (!tmp[idx])
				tmp[idx] = board2[i][j];
			else if (tmp[idx] == board2[i][j])
				tmp[idx++] *= 2;
			else
				tmp[++idx] = board2[i][j];
		}
		memcpy(board2[i], tmp, sizeof tmp);
	}
}

void dfs(int k) {
	if (k == 5) {
		memcpy(board2, board, sizeof board);
		for (int i = 0; i < 5; ++i) {
			for (int r = 0; r < dir[i]; ++r) rotate();
			swipe();
		}

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) ans = max(ans, board2[i][j]);
		return;
	}

	for (int r = 0; r < 4; ++r) {
		dir[k] = r;
		dfs(k + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> board[i][j];
	}

	dfs(0);
	cout << ans;
}
