#include <bits/stdc++.h>
using namespace std;

#define GO 0
#define WALL 1
#define VISIT -1

int N, M, r, c, d, ans;
int board[50][50];
int dx[4] = {-1, 0, 1, 0}; // 북, 동, 남, 서
int dy[4] = {0, 1, 0, -1};

void run() {
  while (board[r][c] != WALL) {
    if (board[r][c] == GO) ++ans;
    board[r][c] = VISIT;
    // 현재 바라보고 있는 방향 기준으로 90도씩 반시계 방향으로 돌려 봄
    bool flag = 0;
    for (int i = 0; i < 4; ++i) {
      d = (d + 3) % 4; // 반시계 방향
      int nr = r + dx[d], nc = c + dy[d];
      if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
      if (board[nr][nc] == GO) {
        flag = 1;
        r = nr, c = nc;
        break;
      }
    }
    if (flag) continue;
    // 못 들어갔다면 방향 그대로 두고 후진
    r -= dx[d], c -= dy[d];
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> r >> c >> d;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) cin >> board[i][j];
  }

  run();
  cout << ans;
}
