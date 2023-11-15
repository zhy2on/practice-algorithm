#include <iostream>
#include <algorithm>

using namespace std;

int L, C, cnt;
char arr[26], ans[26];

bool is_vowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void dfs(int k, int st) {
	if (k == L) {
		if (cnt < 1) return;
		for (int i = 0; i < k; ++i) cout << ans[i];
		cout << '\n';
		return;
	}

	for (int i = st; i < C; ++i) {
		if (is_vowel(arr[i])) {
			if (L - (cnt + 1) < 2) continue;
			++cnt;
		}
		ans[k] = arr[i];
		dfs(k + 1, i + 1);
		if (is_vowel(arr[i])) --cnt;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;

	for (int i = 0; i < C; ++i) cin >> arr[i];
	sort(arr, arr + C);
	dfs(0, 0);
}
