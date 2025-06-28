#include <bits/stdc++.h>
using namespace std;

int cnt, ans;
int N, r, c;
int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 1, 0};

void func(int x, int y, int k) {
	if (k == 1) {
		if (x == r && y == c) ans = cnt;
		++cnt;
		return;
	}

	func(x, y, k / 2);
	func(x, y + k / 2, k / 2);
	func(x + k / 2, y, k / 2);
	func(x + k / 2, y + k / 2, k / 2);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> r >> c;
	func(0, 0, 1LL << N);
	cout << ans;
}
