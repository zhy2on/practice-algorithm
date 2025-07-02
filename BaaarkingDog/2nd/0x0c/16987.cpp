#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, ans, cnt;
pair<int, int> arr[10];

void dfs(int k) {
	if (k == n) {
		ans = max(ans, cnt);
		return;
	}
	if (arr[k].X <= 0 ||
		cnt == n - 1) {	 // 내가 더이상 칠 수 없을 때는 그냥 지나감
		dfs(k + 1);
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (i == k || arr[i].X <= 0) continue;
		arr[k].X -= arr[i].Y;
		arr[i].X -= arr[k].Y;
		if (arr[k].X <= 0) ++cnt;
		if (arr[i].X <= 0) ++cnt;
		dfs(k + 1);
		if (arr[k].X <= 0) --cnt;
		if (arr[i].X <= 0) --cnt;
		arr[k].X += arr[i].Y;
		arr[i].X += arr[k].Y;
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
