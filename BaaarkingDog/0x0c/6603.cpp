#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

int arr[50], ans[50], n;

void dfs(int k, int st) {
	if (k == 6) {
		for (int i = 0; i < k; ++i) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i < n; ++i) {
		ans[k] = arr[i];
		dfs(k + 1, i + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> n;
		if (!n) return 0;
		for (int i = 0; i < n; ++i) cin >> arr[i];
		dfs(0, 0);
		cout << '\n';
	}
}
