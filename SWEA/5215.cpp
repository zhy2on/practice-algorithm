#include <bits/stdc++.h>
using namespace std;

#define SCORE first
#define CALO second

int T, n, l, ans;
pair<int, int> foods[20];

void dfs(int k, int sc, int calo) {
	if (calo < l) {
		ans = max(ans, sc);
	}

	if (k == n || calo >= l) {
		return;
	}
	dfs(k + 1, sc, calo);
	dfs(k + 1, sc + foods[k].SCORE, calo + foods[k].CALO);
}

void run(int t) {
	cin >> n >> l;

	for (int i = 0; i < n; ++i) {
		cin >> foods[i].SCORE >> foods[i].CALO;
	}
	ans = 0;
	dfs(0, 0, 0);
	cout << '#' << t << ' ' << ans << '\n';
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; ++t) run(t);
}
