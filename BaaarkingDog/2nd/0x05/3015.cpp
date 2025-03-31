#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	stack<pair<int, int> > s;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		int cnt = 1;
		while (!s.empty() && s.top().first <= k) {
			ans += s.top().second;
			if (s.top().first == k) cnt += s.top().second;
			s.pop();
		}
		if (!s.empty()) ans += 1;
		s.push({k, cnt});
	}
	cout << ans;
}

/*
5
5
5
1
1
5
*/
