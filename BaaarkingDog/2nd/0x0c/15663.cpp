#include <bits/stdc++.h>
using namespace std;

int n, m, arr[10], ans[10];
bool isused[10];

void f(int k) {
	if (k == m) {
		for (int i = 0; i < k; ++i) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	int last = 0;
	for (int i = 0; i < n; ++i) {
		if (isused[i]) continue;
		if (last == arr[i]) continue;
		isused[i] = 1;
		ans[k] = arr[i];
		last = arr[i];
		f(k + 1);
		isused[i] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	f(0);
}

// 중복되는 수열을 여러번 출력하면 안 됨
// 중복이려면 1 2 2 2
// 같은 숫자였으면 또 쓰면 안 됨
// 나를 다음 타자가 똑같은 애로 대체될 때

/*
4 4
1 1 1 2
*/
