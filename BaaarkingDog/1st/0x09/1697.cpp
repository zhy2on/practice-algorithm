#include <iostream>
#include <queue>

using namespace std;

int dist[100001];

int main(void) {
	int X, K;
	cin >> X >> K;

	fill(dist, dist + 100001, -1);
	dist[X] = 0;

	queue<int> q;

	q.push(X);

	while(dist[K] == -1) {
		int cur = q.front(); q.pop();
		for(int nx : {cur - 1, cur + 1, cur * 2}) {
			if (nx < 0 || nx > 100000 || dist[nx] != -1) continue;
			dist[nx] = dist[cur] + 1;
			q.push(nx);
		}
	}
	cout << dist[K];
}
