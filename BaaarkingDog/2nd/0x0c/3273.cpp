#include <bits/stdc++.h>
using namespace std;

bool cnt[2000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		cnt[k] = 1;
	}
	cin >> x;

	int ans = 0;
	for (int i = 1; i < (x + 1) / 2; ++i) {
		if (cnt[i] && cnt[x - i]) ans++;
	}
	cout << ans;
}
