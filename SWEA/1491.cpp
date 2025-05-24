#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;

	cin >> T;
	for (int t = 1; t <= T; ++t) {
		long long n, a, b;

		cin >> n >> a >> b;
		long long ans = LLONG_MAX;
		for (int r = 1; r <= sqrt(n); ++r) {
			for (int c = 1; c <= n / r; ++c) {
				ans = min(ans, a * abs(r - c) + b * (n - r * c));
			}
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
}
