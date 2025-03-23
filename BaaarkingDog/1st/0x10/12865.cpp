#include <bits/stdc++.h>
using namespace std;

int dp[101][100001];
int item[101][2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> item[i][0] >> item[i][1];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			dp[i][j] = dp[i - 1][j];
			int w = item[i][0];
			if (w <= j) dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + item[i][1]);
		}
	}
	cout << dp[n][k];
}
