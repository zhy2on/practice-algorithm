#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, V;
vector<int> e[1002];
bool vis[1002] = {};

void dfs(int cur) {
    vis[cur] = true;
    cout << cur << ' ';
    for (int nxt : e[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

void bfs() {
    queue<int> q;
    bool vis[1002] = {};

    q.push(V);
    vis[V] = true;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for (int nxt : e[cur]) {
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> V;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) sort(e[i].begin(), e[i].end());

    dfs(V);
    cout << '\n';
    bfs();
}
