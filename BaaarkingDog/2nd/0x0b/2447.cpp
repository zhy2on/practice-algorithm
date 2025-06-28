#include <bits/stdc++.h>
using namespace std;

char board[2200][2200];

void f(int r, int c, int n) {
	if (n == 1) {
		board[r][c] = '*';
		return;
	}
	n /= 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == 1 && j == 1) continue;
			f(r + n * i, c + n * j, n);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) fill(board[i], board[i] + n, ' ');
	f(0, 0, n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cout << board[i][j];
		cout << '\n';
	}
}
