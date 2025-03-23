#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	dp[0] = 1;
	dp[1] = 2;

	for (int i = 2; i < n; ++i) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
	}

	cout << dp[n - 1];
}
