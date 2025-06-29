#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans[10];

void f(int k, int start) {
	if (k == m) {
		for (int i = 0; i < m; ++i) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; ++i) {
		ans[k] = i;
		f(k + 1, i + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	f(0, 1);
}
