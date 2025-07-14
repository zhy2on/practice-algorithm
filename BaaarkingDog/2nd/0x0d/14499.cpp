#include <bits/stdc++.h>
using namespace std;

int board[20][20];
int N, M, x, y, K;
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int dice[6];

/*
  1
3 0 2
  4
  5
*/
void roll(int d) {
	int tmp[6];
	memcpy(tmp, dice, sizeof dice);

	if (d == 1) {
		dice[0] = tmp[2];
		dice[2] = tmp[5];
		dice[3] = tmp[0];
		dice[5] = tmp[3];
	} else if (d == 2) {
		dice[0] = tmp[3];
		dice[2] = tmp[0];
		dice[3] = tmp[5];
		dice[5] = tmp[2];
	} else if (d == 3) {
		dice[0] = tmp[1];
		dice[1] = tmp[5];
		dice[4] = tmp[0];
		dice[5] = tmp[4];
	} else if (d == 4) {
		dice[0] = tmp[4];
		dice[1] = tmp[0];
		dice[4] = tmp[5];
		dice[5] = tmp[1];
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) cin >> board[i][j];
	}

	while (K--) {
		int d;
		cin >> d;
		int nx = x + dx[d], ny = y + dy[d];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

		roll(d);
		if (board[nx][ny] == 0)
			board[nx][ny] = dice[0];
		else {
			dice[0] = board[nx][ny];
			board[nx][ny] = 0;
		}
		cout << dice[5] << '\n';
		x = nx, y = ny;
	}
}
