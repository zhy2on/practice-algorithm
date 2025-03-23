#include <bits/stdc++.h>
using namespace std;

int arr[1001], dp[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i]) dp[i] = max(dp[i], arr[i] + dp[j]);
		}
	}
	cout << *max_element(dp, dp + n);
}
