#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, X;
vector<int> adj[100002];
bool vis[100002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }

    cin >> X;
    int cnt = 0;
    queue<int> q;

    q.push(X);
    vis[X] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ++cnt;

        for (int nxt : adj[cur]) {
            if (vis[nxt]) continue;
            vis[nxt] = true;
            q.push(nxt);
        }
    }
    
    cout << cnt - 1;
}
