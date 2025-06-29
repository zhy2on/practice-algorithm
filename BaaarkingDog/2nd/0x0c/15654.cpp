#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10], ans[10];
bool isused[10];

void f(int k) {
	if (k == m) {
		for (int i = 0; i < k; ++i) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (isused[i]) continue;
		ans[k] = arr[i];
		isused[i] = 1;
		f(k + 1);
		isused[i] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);

	f(0);
}
