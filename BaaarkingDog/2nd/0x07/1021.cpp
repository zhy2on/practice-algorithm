#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) dq.push_back(i);

	int ans = 0;
	while (m--) {
		int t;
		cin >> t;
		int idx = find(dq.begin(), dq.end(), t) - dq.begin();

		while (dq.front() != t) {
			if (idx <= dq.size() / 2) {
				dq.push_back(dq.front());
				dq.pop_front();
			} else {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			++ans;
		}
		dq.pop_front();
	}
	cout << ans;
}
