#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	cin >> dp[0];

	for (int i = 1; i < n; ++i) {
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}

	for (int i = 0; i < m; ++i) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << dp[n2 - 1] - dp[n1 - 2] << '\n';
	}
}
