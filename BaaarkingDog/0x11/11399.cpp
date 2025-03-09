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

	int ans = person[0];
	for (int i = 1; i < n; ++i) {
		person[i] += person[i - 1];
		ans += person[i];
	}
	cout << ans;
}
