#include <bits/stdc++.h>
using namespace std;

int dir[3];
int board[500][500];
bool vis[500][500];

int N, M, x, y, ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void print() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) cout << board[i][j] << ' ';
    cout << '\n';
  }
  cout << '\n';
}

void update() {
  bool vis[500][500] = {};
  int summ = board[x][y];

  int nx = x, ny = y;
  vis[nx][ny] = 1;
  for (int i = 0; i < 3; ++i) {
    nx = nx + dx[dir[i]], ny = ny + dy[dir[i]];
    vis[nx][ny] = 1;
    if (nx < 0 || nx >= N || ny < 0 || ny >= M) return;
    summ += board[nx][ny];
  }
  ans = max(ans, summ);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) cout << vis[i][j] << ' ';
    cout << '\n';
  }
  cout << '\n';
}

void dfs(int k) {
  if (k == 3) {
    update();
    return;
  }
  for (int i = 0; i < 4; ++i) {
    if (k > 0 && i == (dir[k - 1] + 2) % 4) continue;
    dir[k] = i;
    dfs(k + 1);
  }
}

void run() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      x = i;
      y = j;
      dfs(0);
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
