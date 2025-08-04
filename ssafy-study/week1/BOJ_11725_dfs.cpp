#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int p[100001];

void dfs(int cur) {
  for (int nxt : adj[cur]) {
    if (nxt == p[cur]) continue; // 인접노드가 내 부모라면 continue
    p[nxt] = cur; // 아니라면 내가 부모
    dfs(nxt); // dfs 들어감
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
  dfs(1);
  for (int i = 2; i <= N; ++i) cout << p[i] << '\n';
}

/*
트리의 루트 노드는 1
1부터 dfs를 하면 된다
*/
