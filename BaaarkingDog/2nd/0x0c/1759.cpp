#include <bits/stdc++.h>
using namespace std;

int l, c;
char arr[20], skip[20];

int aeiou() {
	int cnt = 0;
	for (int i = 0; i < c; ++i) {
		if (skip[i]) continue;
		char ch = arr[i];
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			++cnt;
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> c;
	for (int i = 0; i < c; ++i) cin >> arr[i];
	sort(arr, arr + c);

	for (int i = l; i < c; ++i) skip[i] = 1;

	do {
		int cnt = aeiou();
		if (cnt == 0 || l - cnt < 2) continue;

		for (int i = 0; i < c; ++i) {
			if (skip[i] == 0) cout << arr[i];
		}
		cout << '\n';
	} while (next_permutation(skip, skip + c));
}
