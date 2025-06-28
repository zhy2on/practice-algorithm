#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll ans;
int N, r, c;

void func(int x, int y, int k, ll cnt) {
	if (k == 1) {
		if (x == r && y == c) ans = cnt;
		return;
	}

	k = k / 2;
	if (x + k <= r && y + k <= c) return func(x + k, y + k, k, cnt + k * k * 3);
	if (x + k <= r && y <= c) return func(x + k, y, k, cnt + k * k * 2);
	if (x <= r && y + k <= c) return func(x, y + k, k, cnt + k * k);
	return func(x, y, k, cnt);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> r >> c;
	func(0, 0, 1LL << N, 0);
	cout << ans;
}
