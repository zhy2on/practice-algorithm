#include <bits/stdc++.h>
using namespace std;

#define NODE first
#define FROM second

int n, m;

int bfs(const vector<int> (&adj)[501]) {
  bool vis[501] = {};
  int cnt = 0;

  // 각 노드별로 트리 찾기
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;

    bool is_cycle = 0;
    queue<pair<int, int>> q;

    q.push({i, 0});
    vis[i] = 1;

    while (!q.empty()) {
      pair<int, int> cur = q.front(); q.pop();
      for (int nxt : adj[cur.NODE]) {
        if (vis[nxt]) {
          if (nxt != cur.FROM) is_cycle = 1;
          continue;
        }
        q.push({nxt, cur.NODE});
        vis[nxt] = 1;
      }
    }
    if (!is_cycle) ++cnt;
  }
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc = 1;
  while (1) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    vector<int> adj[501];
    
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int cnt = bfs(adj);

    cout << "Case " << tc << ": ";
    if (cnt == 0) cout << "No trees.\n";
    else if (cnt == 1) cout << "There is one tree.\n";
    else cout << "A forest of " << cnt << " trees.\n";

    ++tc;
  }
}
