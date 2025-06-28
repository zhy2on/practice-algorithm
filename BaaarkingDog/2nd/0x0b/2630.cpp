#include <bits/stdc++.h>
using namespace std;

int board[130][130];
int cnt[2];

bool check(int x, int y, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[x][y] != board[x + i][y + j]) return false;
		}
	}
	return true;
}

void func(int x, int y, int n) {
	if (check(x, y, n)) {
		cnt[board[x][y]] += 1;
		return;
	}

	n /= 2;
	func(x, y, n);
	func(x, y + n, n);
	func(x + n, y, n);
	func(x + n, y + n, n);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) cin >> board[i][j];
	func(0, 0, N);
	cout << cnt[0] << '\n' << cnt[1];
}
