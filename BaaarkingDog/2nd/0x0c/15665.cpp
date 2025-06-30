#include <bits/stdc++.h>
using namespace std;

int n, m, arr[10], ans[10];

void f(int k) {
	if (k == m) {
		for (int i = 0; i < k; ++i) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; ++i) {
		ans[k] = arr[i];
		f(k + 1);
	}
}

bool in(int k, int size) {
	for (int i = 0; i < size; ++i) {
		if (k == arr[i]) return true;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		if (!in(k, cnt)) arr[cnt++] = k;
	}
	n = cnt;
	sort(arr, arr + n);
	f(0);
}
