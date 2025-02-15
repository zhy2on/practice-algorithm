#include <bits/stdc++.h>

using namespace std;

int dp[1001][3];
int color[1001][3];

int main(void) {
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> color[i][j];
		}
	}

	for (int i = 0; i < 3; ++i) {
		dp[0][i] = color[0][i];
	}

	for (int i = 1; i < n; ++i) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
	}

	cout << min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
}
