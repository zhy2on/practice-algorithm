#include <iostream>

using namespace std;

int board[6561][6561];

int A, B, C;

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
		if (board[r][c] == -1) ++A;
		else if (board[r][c] == 0) ++B;
		else ++C;
		return;
	}
	n /= 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			f(r + i * n, c + j * n, n);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}

	f(0, 0, n);

	cout << A << '\n' << B << '\n' << C;
}
