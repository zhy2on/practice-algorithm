#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

pair<int, int> red, blue, red2, blue2;
char board[10][10], board2[10][10];
int N, M, ans = INT_MAX;
int dir[10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void roll(int &x, int &y, int d) {
  while (1) {
    int nx = x + dx[d], ny = y + dy[d];
    if (nx < 0 || nx >= N || ny < 0 || ny >= M) return;
    if (board2[nx][ny] == '.' || board2[nx][ny] == 'O') {
      x = nx;
      y = ny;
    }
    if (board2[nx][ny] != '.') return;
  }
}

void tilt(int d) {
  board2[red2.X][red2.Y] = '.';
  roll(red2.X, red2.Y, d);
  if (board2[red2.X][red2.Y] != 'O') {
    board2[red2.X][red2.Y] = 'R';
  }

  board2[blue2.X][blue2.Y] = '.';
  roll(blue2.X, blue2.Y, d);
  if (board2[blue2.X][blue2.Y] != 'O') {
    board2[blue2.X][blue2.Y] = 'B';
  }
}

void dfs(int k) {
  if (k == 10) {
    blue2 = blue;
    red2 = red;
    memcpy(board2, board, sizeof board);
    for (int i = 0; i < k; ++i) {
      tilt(dir[i]);
      if (board2[blue2.X][blue2.Y] == 'O') return;
      if (board2[red2.X][red2.Y] == 'O') {
        ans = min(ans, i + 1);
        return;
      }
    }
    return;
  }

  for (int i = 0; i < 4; ++i) {
    if (k > 0 && i == dir[k - 1]) continue;
    dir[k] = i;
    dfs(k + 1);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // 입력
  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> board[i][j];
      if (board[i][j] == 'R') red = {i, j};
      else if (board[i][j] == 'B') blue = {i, j};
    }
  }

  // 출력
  dfs(0);
  if (ans == INT_MAX) cout << -1;
  else cout << ans;
}

/*
. 빈 칸
# 벽
0 구멍
R 빨간 구슬
B 파란 구슬
*/
