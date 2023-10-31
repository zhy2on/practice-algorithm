#include <iostream>

using namespace std;

bool board[128][128];
int cnt[2];

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
		board[r][c] ? ++cnt[1] : ++cnt[0];
		return;
	}
	n /= 2;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			f(r + n * i, c + n * j, n);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> board[i][j];
	}

	f(0, 0, N);
	
	cout << cnt[0] << '\n' << cnt[1];
}
