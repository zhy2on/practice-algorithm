#include <bits/stdc++.h>
using namespace std;

int n, m, arr[10], ans[10];

void f(int k, int st) {
	if (k == m) {
		for (int i = 0; i < k; ++i) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i < n; ++i) {
		ans[k] = arr[i];
		f(k + 1, i);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	f(0, 0);
}
