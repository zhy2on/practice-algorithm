#include <bits/stdc++.h>
using namespace std;

int cnt;
int n;
bool isused[3][35];

void f(int r) {
	if (r == n) {
		++cnt;
		return;
	}

	for (int c = 0; c < n; ++c) {
		if (isused[0][c] || isused[1][r + c] || isused[2][(r - c) + (n - 1)])
			continue;
		isused[0][c] = 1;
		isused[1][r + c] = 1;
		isused[2][(r - c) + (n - 1)] = 1;
		f(r + 1);
		isused[0][c] = 0;
		isused[1][r + c] = 0;
		isused[2][(r - c) + (n - 1)] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	f(0);
	cout << cnt;
}
