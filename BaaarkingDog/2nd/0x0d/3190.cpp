#include <bits/stdc++.h>
using namespace std;

#define APPLE 1
#define SNAKE -1

deque<pair<int, int>> dq;
int N, K, L, d, t;
int board[101][101];
int dx[4] = {0, 1, 0, -1}; // 동, 북, 서, 남
int dy[4] = {1, 0, -1, 0};

bool OOB(int x, int y) {
  return x < 1 || x > N || y < 1 || y > N;
}

void move() {
  ++t;

  auto [head_x, head_y] = dq.front();
  int nx = head_x + dx[d], ny = head_y + dy[d];
  if (OOB(nx, ny) || board[nx][ny] == SNAKE) {
    cout << t;
    exit(0);
  }

  if (board[nx][ny] != APPLE) {
    auto [tail_x, tail_y] = dq.back();
    dq.pop_back();
    board[tail_x][tail_y] = 0;
  }

  dq.push_front({nx, ny});
  board[nx][ny] = SNAKE;
}

void run() {
  dq.push_front({1, 1});
  board[1][1] = SNAKE;

  cin >> L;
  for (int i = 0; i < L; ++i) {
    int X;
    char C;
    cin >> X >> C;

    while (t < X) move();
    if (C == 'L') d = (d + 3) % 4;
    else d = (d + 1) % 4;
  }
  while (1) move();
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for (int i = 0; i < K; ++i) {
    int r, c;
    cin >> r >> c;
    board[r][c] = APPLE;
  }
  run();
  cout << t;
}
