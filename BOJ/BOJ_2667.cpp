#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
char board[28][28];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> cnts;

struct Point { int x; int y; };

void bfs(int sx, int sy) {
    queue<Point> q;
    int cnt = 0;
    q.push({sx, sy});
    board[sx][sy] = 0;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        ++cnt;

        for (int d = 0; d < 4; ++d) {
            int nx = cur.x + dx[d], ny = cur.y + dy[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[nx][ny] == 0) continue;

            board[nx][ny] = 0;
            q.push({nx, ny});
        }
    }
    cnts.push_back(cnt);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
            board[i][j] -= '0';
        }
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 1) {
                bfs(i, j);
            }
        }
    }

    sort(cnts.begin(), cnts.end());
    cout << cnts.size() << '\n';
    for (int cnt : cnts) cout << cnt << '\n';
}
