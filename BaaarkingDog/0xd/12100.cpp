#include <iostream>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N;
pair<int, bool> board1[22][22], board2[22][22];

void rotate() {
	pair<int, bool> tmp[22][22];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			tmp[i][j] = board2[i][j];
	}
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < N; ++i)
			board2[i][j] = tmp[N - 1 - j][i];
	}
}

bool move(int i, int j, int cur) {
	if ((board2[i][cur].X == board2[i][j].X) && !board2[i][j].Y) {
		board2[i][cur] = {board2[i][cur].X * 2, 1};
		board2[i][j] = {0, 0};
		return true;
	}
	if (board2[i][cur].X) {
		if (cur + 1 == j) return true;
		board2[i][cur + 1] = board2[i][j];
		board2[i][j] = {0, 0};
		return true;
	}
	if (cur == 0) {
		board2[i][cur] = board2[i][j];
		board2[i][j] = {0, 0};
		return true;
	}
	return false;
}

void swipe() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) board2[i][j].Y = 0;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!board2[i][j].X) continue;
			int cur = j;
			while (cur--) {
				if (move(i, j, cur)) break;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> board1[i][j].X;
	}

	int from_dir = 0, maxx = 0;
	for (int t = 0; t < (1 << 10); ++t) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) board2[i][j] = board1[i][j];
		}
		int tmp = t;
		for (int i = 0; i < 5; ++i) {
			int to_dir = tmp % 4;
			tmp /= 4;

			while (from_dir != to_dir) {
				++from_dir;
				from_dir %= 4;
				rotate();
			}
			swipe();
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				maxx = max(maxx, board2[i][j].X);
			}
		}
	}

	cout << maxx;
}

/*
4
2 0 0 0
2 2 0 0
2 0 0 0
0 0 0 0
*/
