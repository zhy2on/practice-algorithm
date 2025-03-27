#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	vector<int> v;

	cin >> k;
	for (int i = 0; i < k; ++i) {
		int t;
		cin >> t;
		if (t == 0)
			v.pop_back();
		else
			v.push_back(t);
	}
	long ans = 0;
	while (!v.empty()) {
		ans += v[v.size() - 1];
		v.pop_back();
	}
	cout << ans;
}
