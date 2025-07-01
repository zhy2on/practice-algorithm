#include <bits/stdc++.h>
using namespace std;

int l, c;
char arr[20], ans[20];

int aeiou() {
	int cnt = 0;
	for (int i = 0; i < l; ++i) {
		if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' ||
			ans[i] == 'u')
			++cnt;
	}
	return cnt;
}

void f(int k, int st) {
	if (k == l) {
		int cnt = aeiou();
		if (cnt == 0 || l - cnt < 2) return;
		for (int i = 0; i < l; ++i) cout << ans[i];
		cout << '\n';
		return;
	}

	for (int i = st; i < c; ++i) {
		ans[k] = arr[i];
		f(k + 1, i + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> c;
	for (int i = 0; i < c; ++i) cin >> arr[i];
	sort(arr, arr + c);
	f(0, 0);
}
