#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
int dist[MAX];
deque<int> dq;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	if (n >= k) {
		cout << n - k;
		return 0;
	}

	fill(dist, dist + MAX, -1);
	dist[n] = 0;
	dq.push_front(n);

	while (!dq.empty()) {
		int x = dq.front();
		dq.pop_front();

		if (x == k) break;

		// 순간이동 먼저
		int nx;

		nx = x * 2;
		if (nx < MAX && dist[nx] == -1) {
			dist[nx] = dist[x];
			dq.push_front(nx);
		}

		// 걷기
		for (int dx : {-1, 1}) {
			nx = x + dx;
			if (nx >= 0 && nx < MAX && dist[nx] == -1) {
				dist[nx] = dist[x] + 1;
				dq.push_back(nx);
			}
		}
	}

	cout << dist[k];
}
