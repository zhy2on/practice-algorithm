#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M, ans = -1;
char board[10][10];
int dist[10][10][10][10];
pair<int, int> red, blue;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs() {
  queue<tuple<int, int, int, int>> q;
  q.push({red.X, red.Y, blue.X, blue.Y});
  dist[red.X][red.Y][blue.X][blue.Y] = 1;

  while (!q.empty()) {
    auto [rx, ry, bx, by] = q.front(); q.pop();
    int cnt = dist[rx][ry][bx][by];

    if (cnt > 10) return;

    for (int d = 0; d < 4; ++d) {
      int nrx = rx, nry = ry, nbx = bx, nby = by;
      int move_r = 0, move_b = 0;

      // blue 먼저
      while (board[nbx + dx[d]][nby + dy[d]] == '.') {
        nbx += dx[d];
        nby += dy[d];
        ++move_b;
      }
      
      if (board[nbx + dx[d]][nby + dy[d]] == 'O') continue;

      // red
      while (board[nrx + dx[d]][nry + dy[d]] == '.') {
        nrx += dx[d];
        nry += dy[d];
        ++move_r;
      }

      if (board[nrx + dx[d]][nry + dy[d]] == 'O') {
        ans = cnt;
        return;
      }

      // 둘이 겹쳤다면 늦게 출발한(더 많이 움직인) 구슬을 한 칸 뒤로 이동
      if (nrx == nbx && nry == nby) {
        if (move_r > move_b) {
          nrx -= dx[d];
          nry -= dy[d];
        } else {
          nbx -= dx[d];
          nby -= dy[d];
        }
      }

      if (dist[nrx][nry][nbx][nby]) continue;

      q.push({nrx, nry, nbx, nby});
      dist[nrx][nry][nbx][nby] = cnt + 1;
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
      if (board[i][j] == 'R') {
        red = {i, j};
        board[i][j] = '.';
      }
      else if (board[i][j] == 'B') {
        blue = {i, j};
        board[i][j] = '.';
      }
    }
  }

  bfs();
  cout << ans;
}
