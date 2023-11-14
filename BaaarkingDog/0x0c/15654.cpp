#include <iostream>
#include <algorithm>

using namespace std;

int N, M, arr[8], ans[8];
bool vis[8];

void dfs(int k) {
	if (k == M) {
		for (int i = 0; i < k; ++i) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (vis[i]) continue;
		vis[i] = 1;
		ans[k] = arr[i];
		dfs(k + 1);
		vis[i] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) cin >> arr[i];
	sort(arr, arr + N);

	dfs(0);
}