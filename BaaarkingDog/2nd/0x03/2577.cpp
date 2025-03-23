#include <bits/stdc++.h>
using namespace std;

int cnt[11];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	long long ans = a * b * c;
	int tmp;
	while (ans > 0) {
		tmp = ans % 10;
		ans /= 10;
		cnt[tmp]++;
	}
	for (int i = 0; i < 10; ++i) cout << cnt[i] << '\n';
}
