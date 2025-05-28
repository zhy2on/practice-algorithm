#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
int target[51];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) dq.push_back(i);
	for (int i = 0; i < m; ++i) cin >> target[i];

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		int where;
		for (where = 0; where < dq.size(); ++where) {
			if (dq[where] == target[i]) break;
		}

		if (where <= dq.size() / 2) {
			while (dq.front() != target[i]) {
				dq.push_back(dq.front());
				dq.pop_front();
				++ans;
			}
		} else {
			while (dq.front() != target[i]) {
				dq.push_front(dq.back());
				dq.pop_back();
				++ans;
			}
		}
		dq.pop_front();
	}
	cout << ans;
}
