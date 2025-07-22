#include <bits/stdc++.h>
using namespace std;

int board[500][500];
bool vis[500][500];

int N, M, summ, ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int cx, int cy, int k) {
  if (k == 4) {
    ans = max(ans, summ);
    return;
  }

  for (int d = 0; d < 4; ++d) {
    int nx = cx + dx[d], ny = cy + dy[d];

    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
    if (vis[nx][ny]) continue;

    vis[nx][ny] = 1;
    summ += board[nx][ny];

    dfs(nx, ny, k + 1);
    if (k == 2) {
      dfs(cx, cy, k + 1);
    }

    vis[nx][ny] = 0;
    summ -= board[nx][ny];
  }
}

void run() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      vis[i][j] = 1;
      summ += board[i][j];
      dfs(i, j, 1);
      vis[i][j] = 0;
      summ -= board[i][j];
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) cin >> board[i][j];
  }
  run();
  cout << ans;
}
