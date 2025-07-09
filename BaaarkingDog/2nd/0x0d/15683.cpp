#include <bits/stdc++.h>
using namespace std;

int N, M, cc_num, watched, wall;
int board[8][8], tmp[8][8], dir[8];
tuple<int, int, int> cctv[8];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int watch(int x, int y, int d) {
  int cnt = 0;
  while (1) {
    x += dx[d];
    y += dy[d];
    if (x < 0 || x >= N || y < 0 || y >= M) break;
    if (tmp[x][y] == 6) break;
    if (tmp[x][y] == 0) {
      tmp[x][y] = -1;
      ++cnt;
    }
  }
  return cnt;
}

void simulation() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) tmp[i][j] = board[i][j];
  }

  int cnt = 0;
  for (int i = 0; i < cc_num; ++i) {
    auto [x, y, n] = cctv[i];
    switch (n) {
      case 1:
        cnt += watch(x, y, dir[i]);
        break;
      case 2:
        cnt += watch(x, y, dir[i]);
        cnt += watch(x, y, dir[i] + 2);
        break;
      case 3:
        cnt += watch(x, y, dir[i]);
        cnt += watch(x, y, (dir[i] + 1) % 4);
        break;
      case 4:
        cnt += watch(x, y, dir[i]);
        cnt += watch(x, y, (dir[i] + 1) % 4);
        cnt += watch(x, y, (dir[i] + 2) % 4);
        break;
      case 5:
        cnt += watch(x, y, 0);
        cnt += watch(x, y, 1);
        cnt += watch(x, y, 2);
        cnt += watch(x, y, 3);
        break;
    }
  }
  watched = max(watched, cnt);
}

void dfs(int k) {
  if (k == cc_num) {
    simulation();
    return;
  }

  auto [x, y, n] = cctv[k];
  if (n == 5) {
    dir[k] = 0;
    dfs(k + 1);
  } else if (n == 2) {
    for (int i = 0; i < 2; ++i) {
      dir[k] = i;
      dfs(k + 1);
    }
  } else {
    for (int i = 0; i < 4; ++i) {
      dir[k] = i;
      dfs(k + 1);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> board[i][j];
      if (board[i][j] >= 1 && board[i][j] <= 5)
        cctv[cc_num++] = {i, j, board[i][j]};
      if (board[i][j] == 6) ++wall;
    }
  }

  dfs(0);
  cout << N * M - wall - cc_num - watched;
}
