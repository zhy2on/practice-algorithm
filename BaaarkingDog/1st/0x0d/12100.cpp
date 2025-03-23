#include <iostream>
#include <algorithm>

using namespace std;

int N;
int board1[22][22], board2[22][22];

void rotate() {
	int tmp[22][22];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			tmp[i][j] = board2[i][j];
	}
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < N; ++i)
			board2[i][j] = tmp[N - 1 - j][i];
	}
}

void swipe() {
	for (int i = 0; i < N; ++i) {
		int idx = 0;
		int tmp[22] = {};
		for (int j = 0; j < N; ++j) {
			if (!board2[i][j]) continue;
			if (!tmp[idx]) tmp[idx] = board2[i][j];
			else if (tmp[idx] == board2[i][j]) tmp[idx++] *= 2;
			else tmp[++idx] = board2[i][j];
		}
		for (int j = 0; j < N; ++j) board2[i][j] = tmp[j];
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> board1[i][j];
	}

	int maxx = 0;
	for (int t = 0; t < (1 << 10); ++t) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) board2[i][j] = board1[i][j];
		}
		int tmp = t;
		for (int i = 0; i < 5; ++i) {
			int dir = tmp % 4;
			tmp /= 4;

			while (dir--) rotate();
			swipe();
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) maxx = max(maxx, board2[i][j]);
		}
	}

	cout << maxx;
}
