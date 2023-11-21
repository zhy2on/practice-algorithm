#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define X first
#define Y second

char board[5][5];
int arr[7], combi7[5][5], ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(int r, int c) {
	queue<pair<int, int> > q;
	bool vis[5][5] = {};
	int cnt = 0;

	q.push(pair(r, c));
	vis[r][c] = 1;

	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front(); q.pop();
		++cnt;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if (vis[nx][ny] || !combi7[nx][ny]) continue;

			vis[nx][ny] = 1;
			q.push({nx, ny});
		}
	}
	return cnt;
}

void dfs(int k, int st, int dasom) {
	if (k == 7) {
		if (dasom >= 4 && bfs(arr[0] / 5, arr[0] % 5) == 7) ++ans;
		return;
	}
	
	for (int i = st; i < 25; ++i) {
		arr[k] = i;
		combi7[i / 5][i % 5] = 1; // bfs를 하기 위해 뽑힌 자리를 체크해준다.
		dfs(k + 1, i + 1, dasom + (board[i / 5][i % 5] == 'S'));
		combi7[i / 5][i % 5] = 0; // dfs를 돌고 나온 후니까 다시 0으로 바꿔줌.
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) cin >> board[i][j];
	}

	dfs(0, 0, 0);

	cout << ans;
}
