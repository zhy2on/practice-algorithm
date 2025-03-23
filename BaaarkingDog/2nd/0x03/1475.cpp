#include <bits/stdc++.h>
using namespace std;

int cnt[11];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	while (n > 0) {
		cnt[n % 10]++;
		n /= 10;
	}

	cnt[6] = (cnt[6] + cnt[9] + 1) / 2;
	cnt[9] = cnt[6];
	cout << *max_element(cnt, cnt + 10);
}
