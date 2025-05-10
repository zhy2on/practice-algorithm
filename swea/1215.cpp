#include <bits/stdc++.h>

using namespace std;

int find_palindrome(int n, string board[8]) {
	int cnt = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			int k = 0;
			for (k = 0; (n + j - 1) < 8 && k < n / 2; ++k) {
				if (board[i][j + k] != board[i][(n + j - 1) - k]) break;
			}
			if (k == n / 2) ++cnt;

			k = 0;
			for (k = 0; (n + i - 1) < 8 && k < n / 2; ++k) {
				if (board[i + k][j] != board[(n + i - 1) - k][j]) break;
			}
			if (k == n / 2) ++cnt;
		}
	}
	return cnt;
}

int main(void) {
	for (int i = 0; i < 10; ++i) {
		int n;
		cin >> n;

		string board[8];

		for (int j = 0; j < 8; ++j) {
			cin >> board[j];
		}
		int cnt = find_palindrome(n, board);
		cout << '#' << i + 1 << ' ' << cnt << '\n';
	}
}
