#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define X first
#define Y second
int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502];
int n = 7, m = 10; // n = 행의 수, m = 열의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미

int main(void) {
	queue<pair<int, int> > Q;
	vis[0][0] = 1;
	Q.push({0,0});
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || !board[nx][ny]) continue;
			vis[nx][ny] = 1;
			Q.push({nx, ny});
		}
	}
}
