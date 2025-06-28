#include <bits/stdc++.h>
using namespace std;

char board[4000][8000];

void f(int r, int c, int n) {
	if (n == 3) {
		board[r][c] = '*';
		board[r + 1][c - 1] = board[r + 1][c + 1] = '*';
		for (int i = -2; i <= 2; ++i) board[r + 2][c + i] = '*';
		return;
	}
	n /= 2;
	f(r, c, n);
	f(r + n, c - n, n);
	f(r + n, c + n, n);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) fill(board[i], board[i] + N * 2 - 1, ' ');
	f(0, N - 1, N);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N * 2 - 1; ++j) cout << board[i][j];
		cout << '\n';
	}
}

// 가로 3*2^k
// 세로 3*2^(k+1) -1
// 세로 = 가로 * 2 - 1
