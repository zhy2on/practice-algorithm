#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, vs[10], ans;
pair<int, int> arr[10];

int break_eggs() {
	pair<int, int> eggs[10];
	for (int i = 0; i < n; ++i) eggs[i] = arr[i];

	for (int i = 0; i < n; ++i) {
		if (eggs[i].X <= 0 || eggs[vs[i]].X <= 0) continue;
		eggs[i].X -= eggs[vs[i]].Y;
		eggs[vs[i]].X -= eggs[i].Y;
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (eggs[i].X <= 0) ++cnt;
	}
	return cnt;
}

void dfs(int k) {
	if (k == n) {
		ans = max(ans, break_eggs());
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (i == k) continue;
		vs[k] = i;
		dfs(k + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i].X >> arr[i].Y;
	dfs(0);
	cout << ans;
}
