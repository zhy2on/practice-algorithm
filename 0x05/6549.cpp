#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;
#define X first
#define Y second

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		int n;
		cin >> n;
		if (!n) break;

		long long ans = 0;
		stack<pair<int, int> > s;
		for (int i = 0; i < n; ++i) {
			int h;
			cin >> h;
			int idx = i;
			while (!s.empty() && s.top().X >= h) {
				ans = max(ans, 1LL * (i - s.top().Y) * s.top().X);
				idx = s.top().Y;
				s.pop();
			}
			s.push(make_pair(h, idx));
		}

		while (!s.empty()) {
			ans = max(ans, 1LL * (n - s.top().Y) * s.top().X);
			s.pop();
		}

		cout << ans << '\n';
	}
}
