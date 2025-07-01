#include <bits/stdc++.h>
using namespace std;

int arr[15], ans[6], k;

void f(int d, int st) {
	if (d == 6) {
		for (int i = 0; i < d; ++i) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i < k; ++i) {
		ans[d] = arr[i];
		f(d + 1, i + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; ++i) cin >> arr[i];
		f(0, 0);
		cout << '\n';
	}
}
