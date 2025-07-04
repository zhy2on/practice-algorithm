#include <bits/stdc++.h>
using namespace std;

int N, M;

void run(int t) {
	int A[21], B[21];
	int *arr = A, *brr = B;

	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < M; ++i) cin >> B[i];

	if (N > M) {
		swap(arr, brr);
		swap(N, M);
	}

	int ans = 0;
	for (int i = 0; i < M - N + 1; ++i) {
		int tmp = 0;
		for (int j = 0; j < N; ++j) {
			tmp += arr[j] * brr[i + j];
		}
		ans = max(ans, tmp);
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
