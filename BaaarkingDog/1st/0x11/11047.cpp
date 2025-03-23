#include <bits/stdc++.h>
using namespace std;

int coin[11];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, index = -1;

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> coin[i];
		if (coin[i] <= k) index = i;
	}

	int ans = 0;
	for (int i = index; i >= 0; --i) {
		if (k < coin[i]) continue;
		ans += k / coin[i];
		k = k % coin[i];
	}
	cout << ans;
}
