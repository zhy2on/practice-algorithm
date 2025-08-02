#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define RED 1
#define BLUE 2

int N, M, ans = INT_MAX;
char board[10][10], board2[10][10];
pair<int, int> red, blue, red2, blue2;
bool is_red_fall, is_blue_fall;
int tilt_d[10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int who_first(int dir) {
  if (dir == 0) {
    if (red2.X > blue2.X) return RED;
    return BLUE;
  } else if (dir == 1) {
    if (red2.Y < blue2.Y) return RED;
    return BLUE;
  } else if (dir == 2) {
    if (red2.X < blue2.X) return RED;
    return BLUE;
  } else if (dir == 3) {
    if (red2.Y > blue2.Y) return RED;
    return BLUE;
  }
  return -1;
}

void roll(int &x, int &y, int dir, bool &is_fall) {
  char ball = board2[x][y];
  board2[x][y] = '.';
  while (1) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (board2[nx][ny] != '.') {
      if (board2[nx][ny] == 'O') is_fall = true;
      break;
    }
    x = nx;
    y = ny;
  }
  if (!is_fall) board2[x][y] = ball;
}

void tilt(int dir) {
  int who = who_first(dir);
  if (who == RED) {
    roll(red2.X, red2.Y, dir, is_red_fall);
    roll(blue2.X, blue2.Y, dir, is_blue_fall);
  } else {
    roll(blue2.X, blue2.Y, dir, is_blue_fall);
    roll(red2.X, red2.Y, dir, is_red_fall);
  }
}

void init() {
  memcpy(board2, board, sizeof board);
  red2 = red;
  blue2 = blue;
  is_red_fall = is_blue_fall = false;
}

void dfs(int k) {
  if (k == 10) {
    init();
    for (int i = 0; i < 10; ++i) {
      tilt(tilt_d[i]);
      if (is_blue_fall) return;
      if (is_red_fall) {
        ans = min(ans, i);
        return;
      }
    }
    return;
  }
  for (int d = 0; d < 4; ++d) {
    if (k > 0 && tilt_d[k - 1] == d) continue;
    tilt_d[k] = d;
    dfs(k + 1);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> board[i][j];
      if (board[i][j] == 'R') red = {i, j};
      else if (board[i][j] == 'B') blue = {i, j};
    }
  }
  dfs(0);
  if (ans == INT_MAX) cout << -1;
  else cout << ans;
}

/*
. 빈 칸
# 벽
O 구멍
R 빨간 구슬
B 파란 구슬
*/
