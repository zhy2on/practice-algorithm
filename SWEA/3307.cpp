#include <bits/stdc++.h>
using namespace std;

int arr[1000], dp[1000];

void run(int t) {
	int n;
	cin >> n;

	int ans = 1;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << '#' << t << ' ' << ans << '\n';
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) run(t);
}
