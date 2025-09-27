#include <iostream>
#include <queue>

using namespace std;

static int INF = 1e9 + 10;
int N, Q;
char board[52][52];
int dist3[52][52][6];
int sr, sc, tr, tc;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

// 다익스트라 - 누적 최단거리를 선택

struct Node {
  int dist;
  int r, c, p;
  bool operator<(const Node &o) const { return dist > o.dist; }
};

bool OOB(int r, int c) {
  return r < 0 || r >= N || c < 0 || c >= N;
}

int dijkstra() {
  // init dist3
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int p = 0; p <= 5; ++p) dist3[i][j][p] = INF;
    }
  }

  // 처음 pq 넣기, d[from] 채우기
  priority_queue<Node> pq;
  dist3[sr][sc][1] = 0;
  pq.push({0, sr, sc, 1});

  while (!pq.empty()) {
    auto cur = pq.top(); pq.pop();

    if (cur.dist != dist3[cur.r][cur.c][cur.p]) continue;
    if (cur.r == tr && cur.c == tc) return cur.dist;

    for (int dir = 0; dir < 4; ++dir) {
      for (int k = 1; k <= 5; ++k) {
        int nr = cur.r + k * dr[dir];
        int nc = cur.c + k * dc[dir];

        if (OOB(nr, nc) || board[nr][nc] == '#') break;
        if (board[nr][nc] == 'S') continue;

        int power_change_cost = 0;
        for (int j = cur.p; j < k; ++j) {
          power_change_cost += (j + 1) * (j + 1);
        }

        if (k < cur.p) power_change_cost = 1;

        int jump_cost = 1;
        int total_cost = cur.dist + power_change_cost + jump_cost;

        if (total_cost < dist3[nr][nc][k]) {
          dist3[nr][nc][k] = total_cost;
          pq.push({total_cost, nr, nc, k});
        }
      }
    }
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) cin >> board[i][j];
  }

  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    cin >> sr >> sc >> tr >> tc;
    --sr; --sc; --tr; --tc; // 0-based;
    cout << dijkstra() << '\n';
  }
}
