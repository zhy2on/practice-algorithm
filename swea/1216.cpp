#include <bits/stdc++.h>
using namespace std;

int T = 100;

bool check_palindrome_vertical(int start, int end, string board[200], int j) {
	while (start < end) {
		if (board[start][j] != board[end][j]) break;
		++start;
		--end;
	}
	return start >= end;
}

bool check_palindrome_horizon(int start, int end, string board[200], int i) {
	while (start < end) {
		if (board[i][start] != board[i][end]) break;
		++start;
		--end;
	}
	return start >= end;
}

int longest_palindrome(string board[200]) {
	int maxx = 1;
	for (int i = 0; i < T; ++i) {
		for (int j = 0; j < T; ++j) {
			for (int k = T - 1; k - j + 1 > maxx && k > j; --k) {
				if (check_palindrome_horizon(j, k, board, i)) {
					maxx = k - j + 1;
					break;
				}
			}

			for (int k = T - 1; k - i + 1 > maxx && k > i; --k) {
				if (check_palindrome_vertical(i, k, board, j)) {
					maxx = k - i + 1;
					break;
				}
			}
		}
	}
	return maxx;
}

int main(void) {
	for (int i = 0; i < 10; ++i) {
		int n;
		cin >> n;

		string board[200];
		for (int j = 0; j < T; ++j) {
			cin >> board[j];
		}
		cout << '#' << n << ' ' << longest_palindrome(board) << '\n';
	}
}

/*
1
CBCABBAC
BBABCABA
ABCBCCCA
BACCAABB
BCBCACBC
CABACACB
CAAACCAB
CBABACAC
 */
