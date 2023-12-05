#include <iostream>

using namespace std;

int N, M, K, R, C;
int notebook[40][40], sticker[10][10];

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

bool is_attachable(int x, int y) {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (x + i >= N || y + j >= M) return false;
			if (sticker[i][j] && notebook[x + i][y + j]) return false;
		}
	}
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (sticker[i][j]) notebook[x + i][y + j] = sticker[i][j];
		}
	}
	return true;
}

void attach_sticker() {
	for (int r = 0; r < 4; ++r) {
		for (int x = 0; x < N; ++x) {
			for (int y = 0; y < M; ++y) {
				if (is_attachable(x, y)) return;
			}
		}
		rotate();
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	while (K--) {
		cin >> R >> C;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cin >> sticker[i][j];
			}
		}
		attach_sticker();
	}

	int ans = 0;
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < M; ++y) {
			if (notebook[x][y]) ++ans;
		}
	}
	cout << ans;
}
