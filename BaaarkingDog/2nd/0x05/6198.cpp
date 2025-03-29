#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	stack<int> s;

	cin >> n;
	long ans = 0;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		while (!s.empty() && s.top() <= k) s.pop();
		ans += s.size();
		s.push(k);
	}
	cout << ans;
}
