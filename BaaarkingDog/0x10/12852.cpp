#include <bits/stdc++.h>
using namespace std;

int dp[1000001], from[1000001], li[3];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	from[2] = 1;
	from[3] = 2;
	for (int i = 4; i <= n; ++i) {
		for (int i = 0; i < 3; ++i) li[i] = 100000;
		li[0] = dp[i - 1];
		if (i % 2 == 0) li[1] = dp[i / 2];
		if (i % 3 == 0) li[2] = dp[i / 3];

		int minn = li[0], minn_i = 0;
		for (int i = 1; i < 3; ++i) {
			if (li[i] < minn) {
				minn_i = i;
				minn = li[i];
			}
		}
		from[i] = minn_i;
		dp[i] = minn + 1;
	}

	cout << dp[n] << '\n';
	cout << n << ' ';
	while (n > 1) {
		if (from[n] == 0)
			n -= 1;
		else if (from[n] == 1)
			n /= 2;
		else if (from[n] == 2)
			n /= 3;
		cout << n << ' ';
	}
}
