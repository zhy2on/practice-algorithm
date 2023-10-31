#include <iostream>

using namespace std;

bool board[64][64];

void f(int r, int c, int n) {
	bool flag = true;
	for (int i = r; i < r + n; ++i) {
		for (int j = c; j < c + n; ++j) {
			if (board[i][j] != board[r][c]) {
				flag = false;
				break;
			}
		}
	}
	if (flag) {
		cout << board[r][c];
		return;
	}
	n /= 2;
	cout << '(';
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			f(r + i * n, c + j * n, n);
		}
	}
	cout << ')';
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;

	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;

		int j = 0;
		for (auto c : str)
			board[i][j++] = c - '0';
	}

	f(0, 0, N);
}
