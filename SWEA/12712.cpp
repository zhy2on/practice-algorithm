#include <bits/stdc++.h>
using namespace std;

int N, M;

int spray(int board[20][20], int dx[4], int dy[4], int x, int y) {
	int cnt = board[x][y];
	for (int i = 1; i < M; ++i) {
		for (int d = 0; d < 4; ++d) {
			int nx = x + i * dx[d], ny = y + i * dy[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			cnt += board[nx][ny];
		}
	}
	return cnt;
}

int x(int board[20][20]) {
	int dx[4] = {-1, 1, 1, -1};
	int dy[4] = {1, 1, -1, -1};

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			ans = max(ans, spray(board, dx, dy, i, j));
		}
	}
	return ans;
}

int pl(int board[20][20]) {
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, -1, 0, 1};

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			ans = max(ans, spray(board, dx, dy, i, j));
		}
	}
	return ans;
}

void run(int t) {
	int board[20][20] = {};

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> board[i][j];
	}

	int ans = max(pl(board), x(board));
	cout << '#' << t << ' ' << ans << '\n';
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) run(t);
}

// N*N배열. M세기만큼 스프레이. 중심에서 스프레이 분사. + or x 형태.
// 중심을 다 다르게 해야함
/*
2
5 2
1 3 3 6 7
8 13 9 12 8
4 16 11 12 6
2 4 1 23 2
9 13 4 7 3
*/
