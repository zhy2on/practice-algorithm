#include <bits/stdc++.h>
using namespace std;

long long ans;

void get_sum(vector<int> v) {
	while (v.size() > 1) {
		ans += v[v.size() - 1] * v[v.size() - 2];
		v.pop_back();
		v.pop_back();
	}
	if (v.size()) ans += v[0];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;

	cin >> n;
	vector<int> vP, vN;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		if (k == 1)
			++ans;
		else if (k > 0)
			vP.push_back(k);
		else
			vN.push_back(k);
	}
	sort(vP.begin(), vP.end());
	sort(vN.begin(), vN.end(), greater<int>());
	get_sum(vP);
	get_sum(vN);
	cout << ans;
}
