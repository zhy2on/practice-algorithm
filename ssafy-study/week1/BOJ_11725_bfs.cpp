#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int p[100001];

void bfs() {
  queue<int> q;
  q.push(1);

  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : adj[cur]) {
      if (p[nxt]) continue; // 이미 부모 노드가 정해졌으면 continue
      q.push(nxt);
      p[nxt] = cur;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  bfs();
  for (int i = 2; i <= N; ++i) cout << p[i] << '\n';
}
