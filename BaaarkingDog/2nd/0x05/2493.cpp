#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int> > s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;

	cin >> n;

	s.push({100000001, 0});

	for (int i = 1; i <= n; ++i) {
		int t;
		cin >> t;

		while (s.top().first < t) s.pop();
		cout << s.top().second << ' ';
		s.push({t, i});
	}
}
