#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int arr[20];

void f(int cur, int sum) {
	if (cur == n) {
		if (sum == s) ++cnt;
		return;
	}

	f(cur + 1, sum);			 // 내가 포함되지 않음
	f(cur + 1, sum + arr[cur]);	 // 내가 포함 됨
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	f(0, 0);
	if (s == 0) --cnt;	// 공집합의 합도 0이므로
	cout << cnt;
}
