#include <bits/stdc++.h>

using namespace std;

int dp[301], stair[301];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> stair[i];
	}
	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < n; ++i) {
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}
	cout << dp[n - 1];
}

/*
n-2 최댓값 + 현재
n-3 최댓값 + n-1 값 + 현재
*/
