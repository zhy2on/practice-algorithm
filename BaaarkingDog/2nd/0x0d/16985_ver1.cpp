#include <bits/stdc++.h>
using namespace std;

int board_raw[5][5][5];   // 입력 원본
int rotated[5][4][5][5];  // [층][회전][i][j]
int board[5][5][5];       // 최종 큐브
int r[5], p[5], ans = INT_MAX;
bool isused[5];

int du[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, 1, 0, -1, 0};
int dy[6] = {0, 0, 0, -1, 0, 1};

void rotate_layer(int dst[5][5], int src[5][5]) {
  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < 5; ++j) dst[j][4 - i] = src[i][j];
}

void preprocess() {
  for (int n = 0; n < 5; ++n) {
    // 0도 회전
    for (int i = 0; i < 5; ++i)
      for (int j = 0; j < 5; ++j) rotated[n][0][i][j] = board_raw[n][i][j];
    // 90, 180, 270도 회전
    for (int k = 1; k < 4; ++k) rotate_layer(rotated[n][k], rotated[n][k - 1]);
  }
}

void bfs() {
  if (board[0][0][0] == 0 || board[4][4][4] == 0) return;

  queue<tuple<int, int, int>> q;
  int dist[5][5][5] = {};
  q.push({0, 0, 0});
  dist[0][0][0] = 1;

  while (!q.empty()) {
    auto [u, x, y] = q.front();
    q.pop();
    if (u == 4 && x == 4 && y == 4) {
      ans = min(ans, dist[u][x][y] - 1);
      if (ans == 12) {
        cout << 12;
        exit(0);
      }
      return;
    }
    if (dist[u][x][y] > ans) continue;

    for (int i = 0; i < 6; ++i) {
      int nu = u + du[i], nx = x + dx[i], ny = y + dy[i];
      if (nu < 0 || nu >= 5 || nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
      if (dist[nu][nx][ny] || board[nu][nx][ny] == 0) continue;
      dist[nu][nx][ny] = dist[u][x][y] + 1;
      q.push({nu, nx, ny});
    }
  }
}

void simulation() {
  for (int i = 0; i < 5; ++i) {
    int pi = p[i];
    int ri = r[i];
    for (int x = 0; x < 5; ++x)
      for (int y = 0; y < 5; ++y) board[i][x][y] = rotated[pi][ri][x][y];
  }

  bfs();
}

void dfs_r(int k) {
  if (k == 5) {
    simulation();
    return;
  }
  for (int i = 0; i < 4; ++i) {
    r[k] = i;
    dfs_r(k + 1);
  }
}

void dfs_p(int k) {
  if (k == 5) {
    dfs_r(0);
    return;
  }
  for (int i = 0; i < 5; ++i) {
    if (isused[i]) continue;
    isused[i] = 1;
    p[k] = i;
    dfs_p(k + 1);
    isused[i] = 0;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int n = 0; n < 5; ++n)
    for (int i = 0; i < 5; ++i)
      for (int j = 0; j < 5; ++j) cin >> board_raw[n][i][j];

  preprocess();  // 회전 상태 미리 계산
  dfs_p(0);      // 쌓는 순서 + 회전 순서 조합 탐색

  if (ans == INT_MAX)
    cout << -1;
  else
    cout << ans;
}
