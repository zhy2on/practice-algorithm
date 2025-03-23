#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
	int n, m;

	cin >> n >> m;

	string str;

	for (int i = 0; i < n; ++i) {
		cin >> str;
		for (int j = 0; j < str.length(); ++j) {
			board[i][j] = str[j] - '0';
		}
	}

	vis[0][0] = 1;
	queue<pair<int, int> > q;
	q.push({0, 0});

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || !board[nx][ny]) continue;

			vis[nx][ny] = 1;
			q.push({nx, ny});
			board[nx][ny] = board[cur.X][cur.Y] + 1;
		}
	}

	cout << board[n - 1][m - 1];
}
