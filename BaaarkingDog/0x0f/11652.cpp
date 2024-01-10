#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long arr[100001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i) cin >> arr[i];
	sort(arr, arr + N);

	int cnt = 1, maxcnt = 1;
	long long maxval = arr[0];
	for (int i = 1; i < N; ++i) {
		if (arr[i] != arr[i - 1]) {
			if (cnt > maxcnt) {
				maxval = arr[i - 1];
				maxcnt = cnt;
			}
			cnt = 0;
		}
		++cnt;
	}
	if (cnt > maxcnt) {
		maxval = arr[N - 1];
	}

	cout << maxval;
}
