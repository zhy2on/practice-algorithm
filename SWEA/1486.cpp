#include <bits/stdc++.h>
using namespace std;

int n, b, ans;
int h[20];

void dfs(int i, int s) {
	if (s >= b) {
		ans = min(ans, s);
		return;
	}
	if (i == n) return;

	dfs(i + 1, s + h[i]);
	dfs(i + 1, s);
}

void run(int tc) {
	ans = INT_MAX;
	dfs(0, 0);
	cout << '#' << tc << ' ' << ans - b << '\n';
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> n >> b;
		for (int i = 0; i < n; ++i) cin >> h[i];
		run(tc);
	}
}
