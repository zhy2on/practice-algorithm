#include <bits/stdc++.h>
using namespace std;

#define APPLE 1
#define SNAKE -1

deque<pair<int, int>> dq;
queue<pair<int, int>> change;
bool running = 1;
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
    running = 0;
    return;
  }

  if (board[nx][ny] != APPLE) {
    auto [tail_x, tail_y] = dq.back();
    dq.pop_back();
    board[tail_x][tail_y] = 0;
  }

  dq.push_front({nx, ny});
  board[nx][ny] = SNAKE;

  if (!change.empty()) {
    auto [time, dir] = change.front();
    if (time == t) {
      d = (d + dir) % 4;
      change.pop();
    }
  }
}

void run() {
  cin >> L;
  while (L--) {
    int X;
    char C;
    cin >> X >> C;
    if (C == 'L') change.push({X, 3});
    else change.push({X, 1});
  }

  dq.push_front({1, 1});
  board[1][1] = SNAKE;
  while (running) move();
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
