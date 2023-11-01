#include <iostream>

using namespace std;

const int MAX = 1024 * 3 + 2;
char board[MAX][MAX * 2 - 1];

void star(int r, int c, int n) {
	if (n == 3) {
		board[r - 1][c] = ' ';
		return;
	}
	
	n /= 2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			board[r - i][c - j] = ' ';
			board[r - i][c + j] = ' ';
		}
	}

	star(r - n, c, n);
	star(r, c - n, n);
	star(r, c + n, n);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;

	star(N - 1, N - 1, N);

	for (int i = 0; i < N; ++i) {
		fill(board[i], board[i] + N - i - 1, ' ');
		for (int j = 0; j < N + i; ++j) {
			if (board[i][j]) cout << board[i][j];
			else cout << '*';
		}
		for (int j = N + i; j < 2 * N - 1; ++j) cout << ' ';
		cout << '\n';
	}
}
