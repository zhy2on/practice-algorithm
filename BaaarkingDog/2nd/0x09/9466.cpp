#include <bits/stdc++.h>
using namespace std;

int n, s[100001], state[100001], cnt;

const int NOT_VISITED = -1;
const int IN_CYCLE = 0;

void mark_cycle(int start) {
	int cur = s[start];
	state[cur] = IN_CYCLE;
	++cnt;

	while (cur != start) {
		cur = s[cur];
		state[cur] = IN_CYCLE;
		++cnt;
	}
}

void run() {
	cin >> n;
	cnt = 0;

	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		state[i] = NOT_VISITED;
	}

	for (int i = 1; i <= n; ++i) {
		if (state[i] != NOT_VISITED) continue;

		int cur = i;
		while (1) {
			state[cur] = i;
			cur = s[cur];

			if (state[cur] == i) {	// 사이클 발견
				mark_cycle(cur);
				break;
			}
			if (state[cur] != NOT_VISITED) break;  // 이미 탐색했었다면
		}
	}
	cout << n - cnt << '\n';
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) run();
}
