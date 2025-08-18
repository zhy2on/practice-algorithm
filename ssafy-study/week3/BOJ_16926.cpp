#include <bits/stdc++.h>
using namespace std;

int N, M, R;
int board[300][300];
int tmp[300 * 2 + 300 * 2 - 4]; // 시계 방향으로 평탄화
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool rotateLayer(int l, int r) { // layer, rotate
  int n = N - 2 * l;
  int m = M - 2 * l;

  if (n <= 0 || m <= 0) return false;

  int size = n * 2 + m * 2 - 4;

  int d = 0;
  int bx = l, by = l; // board상 레이어의 시작점은 l, l
  int idx = 0;
  int cnt = 0;
  // 평탄화 배열을 보드 시계방향으로 채운다.
  while (cnt < size) {
    tmp[idx++] = board[bx][by];
    bx += dx[d];
    by += dy[d];
    ++cnt;
    if (cnt == m - 1) ++d;
    else if (cnt == m - 1 + n - 1) ++d;
    else if (cnt == m - 1 + n - 1 + m - 1) ++d;
  }

  // cout << "L: " << l << '\n';
  // for (int i = 0; i < size; ++i) cout << tmp[i] << ' ';
  // cout << '\n';

  // 평탄화 배열을 다시 2차원 보드에 덮어씌운다. 평탄화 배열 r번째가 layer 시작점 => r % size임!!!!!!!
  d = 0;
  bx = l, by = l;
  idx = r % size;
  // cout << "tmp[r]: " << tmp[r] << '\n';
  cnt = 0;
  while (cnt < size) {
    board[bx][by] = tmp[idx];
    idx = (idx + 1) % size;
    bx += dx[d];
    by += dy[d];
    // cout << "bx, by, board: " << bx << " " << by << " " << board[bx][by] << "\n";
    ++cnt;
    if (cnt == m - 1) ++d;
    else if (cnt == m - 1 + n - 1) ++d;
    else if (cnt == m - 1 + n - 1 + m - 1) ++d;
  }
  return true;
}

void rotate(int r) {
  int l = 0;
  while (rotateLayer(l, r)) ++l;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> R;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) cin >> board[i][j];
  }

  rotate(R);

  // cout << '\n';

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) cout << board[i][j] << ' ';
    cout << '\n';
  }
}
