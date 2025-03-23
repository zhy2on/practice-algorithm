#include <iostream>

using namespace std;

char board[6561][6561];

void star(int r, int c, int n) {
	if (n == 1) {
		board[r][c] = '*';
		return;
	}

	n /= 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == 1 && j == 1) continue;
			star(r + i * n, c + j * n, n);
		}
	}
}	

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;

	star(0, 0, N);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j]) cout << board[i][j];
			else cout << ' ';
		}
		cout << '\n';
	}
}
