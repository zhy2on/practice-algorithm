#include <bits/stdc++.h>
using namespace std;

int board[40][40];
int sticker[10][10];
int N, M, K, R, C;

bool put(int x, int y) {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (x + i >= N || y + j >= M) return false;
			if (sticker[i][j] && board[x + i][y + j]) return false;
		}
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (sticker[i][j]) board[x + i][y + j] = 1;
		}
	}
	return true;
}

void rotate() {
	int tmp[10][10] = {};

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			tmp[j][R - 1 - i] = sticker[i][j];
		}
	}
	swap(R, C);
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			sticker[i][j] = tmp[i][j];
		}
	}
}

void simulation() {
	for (int d = 0; d < 4; ++d) {
		if (d > 0) rotate();
		for (int x = 0; x < N; ++x) {
			for (int y = 0; y < M; ++y) {
				if (put(x, y)) return;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int k = 0; k < K; ++k) {
		cin >> R >> C;

		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) cin >> sticker[i][j];
		}
		simulation();
	}

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			if (board[i][j]) ++cnt;
	}
	cout << cnt;
}
