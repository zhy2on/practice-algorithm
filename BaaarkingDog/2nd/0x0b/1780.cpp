#include <bits/stdc++.h>
using namespace std;

int board[2200][2200];
int cnt[3];

bool check(int x, int y, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[x][y] != board[x + i][y + j]) return false;
		}
	}
	cnt[board[x][y] + 1] += 1;
	return true;
}

void func(int x, int y, int n) {
	if (check(x, y, n)) return;

	n /= 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) func(x + i * n, y + j * n, n);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> board[i][j];
	}

	func(0, 0, N);
	for (int i = 0; i < 3; ++i) cout << cnt[i] << '\n';
}

/*
3
1 1 1
0 0 0
0 0 0
*/
