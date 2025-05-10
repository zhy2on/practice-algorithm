#include <bits/stdc++.h>

using namespace std;

bool is_palin_row(string board[8], int i, int l, int r) {
	while (l < r) {
		if (board[i][l] != board[i][r]) return false;
		l++;
		r--;
	}
	return true;
}

bool is_palin_col(string board[8], int j, int l, int r) {
	while (l < r) {
		if (board[l][j] != board[r][j]) return false;
		l++;
		r--;
	}
	return true;
}

int find_palindrome(int n, string board[8]) {
	int cnt = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (j + n - 1 < 8 && is_palin_row(board, i, j, j + n - 1)) ++cnt;
			if (i + n - 1 < 8 && is_palin_col(board, j, i, i + n - 1)) ++cnt;
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
