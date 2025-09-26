#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

#define X first
#define Y second

int N, T; // N x N. T일 동안 진행
int F[52][52];
int B[52][52];
bool vis[52][52];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 위 아래 왼쪽 오른쪽
vector<pair<int, int> > jang[3]; // 대표자를 넣어놔야겠음

void init() {
  for (int i = 0; i < N; ++i) {
    fill(vis[i], vis[i] + N, 0);
  }
  for (int i = 0; i < 3; ++i) jang[i].clear();
}

void evening() { // 단일 -> 이중 -> 삼중 그룹 순으로 전파
  // 같은 그룹일 경우 대표자 신앙심 높은 순, 행, 열 번호 작은 순인 그룹이 먼저.
  
  // 정렬 먼저
  for (int i = 0; i < 3; ++i) {
    sort(jang[i].begin(), jang[i].end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
    if (B[a.X][a.Y] != B[b.X][b.Y]) return B[a.X][a.Y] > B[b.X][b.Y];
    if (a.X != b.X) return a.X < b.X;
    return a.Y < b.Y;
  });
  }

  bool already[52][52] = {};
  
  // 전파 시작
  for (int g = 0; g < 3; ++g) {
    for (int i = 0; i < jang[g].size(); ++i) {
      int x = jang[g][i].X, y = jang[g][i].Y;

      if (already[x][y]) continue; // 이미 전파당했다면 continue

      int p = B[x][y] - 1;
      int d = B[x][y] % 4; // 방향
      B[x][y] = 1;
      
      int nx = x, ny = y;
      while (true) { // 전파하기. 음식이 다른 경우만.
        nx += dir[d][0]; ny += dir[d][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || p == 0) break;
        if (F[x][y] == F[nx][ny]) continue;

        if (p > B[nx][ny]) { // 강한 전파
          F[nx][ny] = F[x][y];
          p -= B[nx][ny] + 1;
          ++B[nx][ny];
          already[nx][ny] = true;
        } else { // 약한 전파
          F[nx][ny] |= F[x][y];
          B[nx][ny] += p;
          p = 0;
          already[nx][ny] = true;
        }
      }
    }
  }
}

void grouping(int sx, int sy) { // 대표자 찾고 그룹에 나누기
  vector<pair<int, int> > v; // 그룹 좌표들 넣기
  queue<pair<int, int> > q;
  q.push({sx, sy});
  vis[sx][sy] = 1;
  v.push_back({sx, sy});

  // 그룹 묶기
  while (!q.empty()) {
    auto cur = q.front(); q.pop();

    for (int d = 0; d < 4; ++d) {
      int nx = cur.X + dir[d][0], ny = cur.Y + dir[d][1];
      if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // OOB
      if (vis[nx][ny] || F[nx][ny] != F[sx][sy]) continue; // vis check

      vis[nx][ny] = 1;
      q.push({nx, ny});
      v.push_back({nx, ny});
    }
  }

  // 대표자 뽑고 신앙심 나누기
  sort(v.begin(), v.end());
  int maxI = 0, maxx = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (B[v[i].X][v[i].Y] > maxx) {
      maxx = B[v[i].X][v[i].Y];
      maxI = i;
    }
  }
  int n = F[v[maxI].X][v[maxI].Y];
  if (n == 1 || n == 2 || n == 4) jang[0].push_back({v[maxI].X, v[maxI].Y});
  else if (n == 3 || n == 5 || n == 6) jang[1].push_back({v[maxI].X, v[maxI].Y});
  else jang[2].push_back({v[maxI].X, v[maxI].Y});

  for (int i = 0; i < v.size(); ++i) {
    if (i != maxI) B[v[i].X][v[i].Y] -=1;
  }
  B[v[maxI].X][v[maxI].Y] += v.size() - 1;
}

void lunch() { // bfs 그룹, 대표자 선정
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (!vis[i][j]) grouping(i, j);
    }
  }
}

void morning() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      ++B[i][j];
    }
  }
}

void fSum() {
  int summ[8] = {};
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      switch(F[i][j]) {
        case 7: summ[0] += B[i][j]; break;
        case 6: summ[1] += B[i][j]; break;
        case 5: summ[2] += B[i][j]; break;
        case 3: summ[3] += B[i][j]; break;
        case 1: summ[4] += B[i][j]; break;
        case 2: summ[5] += B[i][j]; break;
        case 4: summ[6] += B[i][j]; break;
      }
    }
  }

  for (int i = 0; i < 7; ++i) cout << summ[i] << ' ';
  cout << '\n';
}

void run() {
  for (int t = 1; t <= T; ++t) {
    init();

    morning();
    lunch();
    evening();

    fSum();
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> T;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      char c;
      cin >> c;
      if (c == 'T') c = 4;
      else if (c == 'C') c = 2;
      else c = 1;
      F[i][j] = c;
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> B[i][j];
    }
  }

  run();
}
