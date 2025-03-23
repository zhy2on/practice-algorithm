#include <bits/stdc++.h>
using namespace std;

int a[502], b[502];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int k;
	cin >> k;
	a[1] = k;

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			cin >> k;
			b[j] = max(a[j - 1], a[j]) + k;
		}
		for (int j = 1; j <= i; ++j) {
			a[j] = b[j];
		}
	}
	cout << *max_element(a + 1, a + n + 1);
}
