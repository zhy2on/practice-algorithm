#include <bits/stdc++.h>
using namespace std;

int board[40][40], tmp[40][40];
int sticker[100][4][10][10];
pair<int, int> rc[100];
int N, M, K;

bool is_ok(int x, int y, int k, int d) {
	// board x,y에 스티커 붙일 수 있는가
	auto [r, c] = rc[k];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) tmp[i][j] = board[i][j];
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (x + i >= N || y + j >= M) return false;
			if (sticker[k][d][i][j] && tmp[x + i][y + j]) return false;
			if (sticker[k][d][i][j]) tmp[x + i][y + j] = sticker[k][d][i][j];
		}
	}
	return true;
}

bool simulation(int k, int d) {
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < M; ++y) {
			if (is_ok(x, y, k, d)) {
				swap(board, tmp);
				return true;
			}
		}
	}
	return false;
}

void rotate(int k, int d) {
	swap(rc[k].first, rc[k].second);
	auto [r, c] = rc[k];
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			sticker[k][d][i][j] = sticker[k][d - 1][c - j - 1][i];
		}
	}
}

void run() {
	for (int k = 0; k < K; ++k) {
		for (int d = 0; d < 4; ++d) {
			if (d > 0) rotate(k, d);
			if (simulation(k, d)) break;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int k = 0; k < K; ++k) {
		int r, c;
		cin >> r >> c;

		rc[k] = {r, c};
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) cin >> sticker[k][0][i][j];
		}
	}

	run();

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			if (board[i][j]) ++cnt;
	}
	cout << cnt;
}
