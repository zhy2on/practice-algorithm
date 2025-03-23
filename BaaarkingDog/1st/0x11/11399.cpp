#include <bits/stdc++.h>
using namespace std;

int person[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> person[i];
	}
	sort(person, person + n);

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += person[i] * (n - i);
	}
	cout << ans;
}
