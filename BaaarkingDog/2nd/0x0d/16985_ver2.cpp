#include <bits/stdc++.h>
using namespace std;

int board[4][5][5][5];
int maze[5][5][5];
int dz[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, 1, 0, -1, 0};
int dy[6] = {0, 0, 0, -1, 0, 1};
int ans = INT_MAX;

bool OOB(int nz, int nx, int ny) {
  return (nz < 0 || nz >= 5 || nx < 0 || nx >= 5 || ny < 0 || ny >= 5);
}

void bfs() {
  queue<tuple<int, int, int>> q;
  int dist[5][5][5] = {};

  // 입구 (0, 0, 0) 출구 (4, 4, 4)
  if (!maze[0][0][0] || !maze[4][4][4]) return;

  q.push({0, 0, 0});
  dist[0][0][0] = 1;
  while (!q.empty()) {
    auto [z, x, y] = q.front();
    q.pop();
    if (dist[z][x][y] >= ans) continue;

    for (int d = 0; d < 6; ++d) {
      int nz = z + dz[d], nx = x + dx[d], ny = y + dy[d];
      if (OOB(nz, nx, ny) || !maze[nz][nx][ny] || dist[nz][nx][ny])
        continue;

      if (nz == 4 && nx == 4 && ny == 4) {
        ans = min(ans, dist[z][x][y]);
        if (ans == 12) {
          cout << 12;
          exit(0);
        }
        return;
      }

      q.push({nz, nx, ny});
      dist[nz][nx][ny] = dist[z][x][y] + 1;
    }
  }
}

void run() {
  int order[5] = {0, 1, 2, 3, 4};
  do {
    for (int mask = 0; mask < 1024; ++mask) {
      int tmp = mask;
      for (int i = 0; i < 5; ++i) {
        int d = tmp % 4;
        memcpy(maze[i], board[d][order[i]], sizeof maze[i]);
        tmp /= 4;
      }
      bfs();
    }
  } while (next_permutation(order, order + 5));
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // 입력
  for (int i = 0; i < 5; ++i) {
    for (int r = 0; r < 5; ++r) {
      for (int c = 0; c < 5; ++c) cin >> board[0][i][r][c];
    }
    // 회전 미리 저장
    for (int d = 1; d < 4; ++d) {
      for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 5; ++c)
          board[d][i][4 - c][r] = board[d - 1][i][r][c];
      }
    }
  }

  run();
  if (ans == INT_MAX)
    cout << -1;
  else
    cout << ans;
}
