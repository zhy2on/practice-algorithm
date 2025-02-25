#include <bits/stdc++.h>
using namespace std;

int dp[1001];
int mod = 10007;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % mod;
	}
	cout << dp[n];
}
