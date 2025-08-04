#include <bits/stdc++.h>
using namespace std;

#define NODE first
#define DIST second

vector<pair<int, int>> adj[1001];

int bfs(int from, int to) {
  bool vis[1001] = {};
  queue<pair<int, int>> q;

  q.push({from, 0});
  vis[from] = 1;

  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    
    for (auto nxt : adj[cur.NODE]) {
      if (vis[nxt.NODE]) continue;
      q.push({nxt.NODE, cur.DIST + nxt.DIST});
      vis[nxt.NODE] = 1;
      if (nxt.NODE == to) return cur.DIST + nxt.DIST;
    }
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N - 1; ++i) {
    int u, v, d;
    cin >> u >> v >> d;
    adj[u].push_back({v, d});
    adj[v].push_back({u, d});
  }

  for (int i = 0; i < M; ++i) {
    int from, to;
    cin >> from >> to;
    cout << bfs(from, to) << '\n';
  }
}
