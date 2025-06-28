#include <bits/stdc++.h>
using namespace std;

char board[70][70];

bool check(int x, int y, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[x][y] != board[x + i][y + j]) return false;
		}
	}
	return true;
}

void f(int x, int y, int n) {
	if (check(x, y, n)) {
		cout << board[x][y];
		return;
	}

	n /= 2;
	cout << '(';
	f(x, y, n);
	f(x, y + n, n);
	f(x + n, y, n);
	f(x + n, y + n, n);
	cout << ')';
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cin >> board[i][j];
	}
	f(0, 0, n);
}
