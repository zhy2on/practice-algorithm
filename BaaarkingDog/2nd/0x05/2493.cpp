#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int> > s;
int ans[500001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int t;
		cin >> t;

		while (!s.empty() && s.top().first < t) {
			int idx = s.top().second;
			s.pop();
			if (!s.empty()) ans[idx] = s.top().second;
		}
		s.push({t, i});
	}

	while (!s.empty()) {
		int idx = s.top().second;
		s.pop();
		if (!s.empty()) ans[idx] = s.top().second;
	}

	for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}
