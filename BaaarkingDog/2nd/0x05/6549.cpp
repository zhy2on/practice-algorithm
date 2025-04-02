#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;

		stack<pair<int, int> > s;
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			int h;
			cin >> h;
			int idx = i;
			while (!s.empty() && s.top().first >= h) {
				idx = s.top().second;
				ans = max(ans, 1LL * (i - s.top().second) * s.top().first);
				s.pop();
			}
			s.push({h, idx});
		}
		while (!s.empty()) {
			ans = max(ans, 1LL * (n - s.top().second) * s.top().first);
			s.pop();
		}
		cout << ans << '\n';
	}
}
