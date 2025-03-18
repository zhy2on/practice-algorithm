#include <bits/stdc++.h>
using namespace std;

int stock[1000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			cin >> stock[j];
		}
		long ans = 0, maxx = stock[n - 1];
		for (int j = n - 2; j >= 0; --j) {
			if (stock[j] > maxx) maxx = stock[j];
			ans += maxx - stock[j];
		}
		cout << ans << '\n';
	}
}
