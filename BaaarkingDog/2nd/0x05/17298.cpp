#include <bits/stdc++.h>
using namespace std;

int ans[1000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;

	cin >> n;
	fill(ans, ans + n, -1);
	stack<pair<int, int> > s;

	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;

		while (!s.empty() && s.top().first < k) {
			ans[s.top().second] = k;
			s.pop();
		}
		s.push({k, i});
	}

	for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
}
