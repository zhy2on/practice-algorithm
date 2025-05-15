#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[10][10];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int t_c = 0; t_c < t; ++t_c) {
		int n;
		cin >> n;

		for (int i = 0; i < 10; ++i) fill(board[i], board[i] + 10, 0);

		int x = 0, y = 0, dir = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				board[x][y] = n * i + j + 1;
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny])
					dir = (dir + 1) % 4;

				x += dx[dir];
				y += dy[dir];
			}
		}

		cout << '#' << t_c + 1 << '\n';
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) cout << board[i][j] << ' ';
			cout << '\n';
		}
	}
}
