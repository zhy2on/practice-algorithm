#include <bits/stdc++.h>
using namespace std;

#define BLOCK first
#define MIXED second

int N, ans;
pair<int, bool> board[20][20];

void rotate() {
	pair<int, bool> tmp[20][20] = {};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			tmp[j][N - 1 - i] = board[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			board[i][j] = tmp[i][j];
		}
	}
}

bool move(int x, int y, int i, int j) {
	if (board[x][y].BLOCK == 0) {
		if (y == 0) {
			board[x][y] = board[i][j];
			board[i][j] = {0, 0};
			return true;
		}
		return false;
	}
	if (!board[x][y].MIXED && board[x][y].BLOCK == board[i][j].BLOCK) {
		board[x][y].BLOCK *= 2;
		board[x][y].MIXED = 1;
		board[i][j] = {0, 0};
		return true;
	}
	if (y + 1 == j) return true;
	board[x][y + 1] = board[i][j];
	board[i][j] = {0, 0};
	return true;
}

void slide() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) board[i][j].MIXED = 0;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			for (int goal = j - 1; goal >= 0; --goal) {
				if (move(i, goal, i, j)) break;
			}
		}
	}
}

void dfs(int k) {
	if (k == 5) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) ans = max(ans, board[i][j].BLOCK);
		return;
	}

	pair<int, bool> backup[20][20];
	for (int r = 0; r < 4; ++r) {
		memcpy(backup, board, sizeof board);  // 상태 저장
		for (int i = 0; i < r; ++i) rotate();
		slide();
		dfs(k + 1);
		memcpy(board, backup, sizeof board);  // 상태 복구
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j].BLOCK;
		}
	}

	dfs(0);
	cout << ans;
}
