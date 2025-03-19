#include <bits/stdc++.h>
using namespace std;

int num[51];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;

	cin >> n;

	int zero = 0, one = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
		if (num[i] == 0) {
			zero = 1;
			i -= 1;
			n -= 1;
		} else if (num[i] == 1) {
			ans += 1;
			i -= 1;
			n -= 1;
		}
	}
	sort(num, num + n);

	int i = n - 1;
	while (num[i] >= 0 && num[i - 1] >= 0 && i >= 1) {
		ans += num[i] * num[i - 1];
		i -= 2;
	}
	if (num[i] >= 0) ans += num[i--];
	// 음수가 홀수 개면
	if (i % 2 == 0) {
		if (!zero) ans += num[i];
		i -= 1;
	}
	while (i >= 0) {
		ans += num[i] * num[i - 1];
		i -= 2;
	}
	cout << ans;
}
