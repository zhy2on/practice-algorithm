#include <bits/stdc++.h>
using namespace std;

pair<int, int> meet[100001];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> meet[i].second >> meet[i].first;
	}
	sort(meet, meet + n);
	int ans = 0;
	int t = 0;
	for (int i = 0; i < n; ++i) {
		if (meet[i].second < t) continue;
		ans += 1;
		t = meet[i].first;
	}
	cout << ans;
}
