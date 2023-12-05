#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K, R, C, ans;
int sticker[10][10], notebook[40][40];

bool is_ok(int x, int y, int i, int j) {
	if (x < 0 || x >= N || y < 0 || y >= M) return false;
	if (sticker[i][j] && notebook[x][y]) return false;
	return true;
}

bool rotation_ok(int x, int y, int angle, bool attach) {
	int oy = y;
	switch (angle) {
		case 0:
			for (int i = 0; i < R; ++x && ++i) {
				for (int j = 0, y = oy; j < C; ++y && ++j) {
					if (attach && sticker[i][j]) notebook[x][y] = sticker[i][j];
					else if (!is_ok(x, y, i, j)) return false;
				}
			}
			break;

		case 90:
			for (int j = 0; j < C; ++x && ++j) {
				for (int i = R - 1, y = oy; i >= 0; ++y && --i) {
					if (attach && sticker[i][j]) notebook[x][y] = sticker[i][j];
					else if (!is_ok(x, y, i, j)) return false;
				}
			}
			break;

		case 180:
			for (int i = R - 1; i >= 0; ++x && --i) {
				for (int j = C - 1, y = oy; j >= 0; ++y && --j) {
					if (attach && sticker[i][j]) notebook[x][y] = sticker[i][j];
					else if (!is_ok(x, y, i, j)) return false;
				}
			}
			break;

		case 270:
			for (int j = C - 1; j >= 0; ++x && --j) {
				for (int i = 0, y = oy; i < R; ++y && ++i) {
					if (attach && sticker[i][j]) notebook[x][y] = sticker[i][j];
					else if (!is_ok(x, y, i, j)) return false;
				}
			}
			break;
	}
	return true;
}

void attach_sticker() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int angle = 0; angle <= 270; angle += 90) {
				if (rotation_ok(i, j, angle, 0)) {
					rotation_ok(i, j, angle, 1);
					return;
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int t = 0; t < K; ++t) {
		for (int i = 0; i < 10; ++i) fill(sticker[i], sticker[i] + 10, 0);
		cin >> R >> C;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) cin >> sticker[i][j];
		}

		attach_sticker();
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (notebook[i][j]) ++ans;
		}
	}

	cout << ans;
}
