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
		if (cnt < 1) return; // 모음이 하나도 없는 경우였다면 그냥 리턴
		for (int i = 0; i < k; ++i) cout << ans[i];
		cout << '\n';
		return;
	}

	for (int i = st; i < C; ++i) {
		if (is_vowel(arr[i])) {
			if (L - (cnt + 1) < 2) continue; // 이번에 모음을 추가했을 때 자음이 2개 미만이 되는 거면 그냥 contiue
			++cnt; // 그게 아니라면 모음이 추가될 것이므로 ++cnt
		}
		ans[k] = arr[i];
		dfs(k + 1, i + 1);
		if (is_vowel(arr[i])) --cnt; // 모음이 추가됐을 때의 상황을 다 돌고 나온 것이기 때문에 다시 --cnt
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
