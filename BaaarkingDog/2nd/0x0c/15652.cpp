#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void f(int k, int st) {
	if (k == m) {
		for (int i = 0; i < k; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i <= n; ++i) {
		arr[k] = i;
		f(k + 1, i);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	f(0, 1);
}
