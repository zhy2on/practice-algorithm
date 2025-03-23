#include <bits/stdc++.h>
using namespace std;

int r[100001];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> r[i];
	sort(r, r + n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, r[i] * (n - i));
	}
	cout << ans;
}
