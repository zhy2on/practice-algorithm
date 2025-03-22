#include <bits/stdc++.h>
using namespace std;

int cnt[101], items[101], multitab[101];
bool is_there[101];
int n, k;

int find_lowest_idx() {
	int minn = 10000;
	int idx = 0;
	for (int i = 0; i < n; ++i) {
		if (cnt[multitab[i]] >= 0 && cnt[multitab[i]] < minn) {
			minn = cnt[multitab[i]];
			idx = i;
		}
	}
	return idx;
}

int main(void) {
	// ios::sync_with_stdio(0);
	// cin.tie(0);

	cin >> n >> k;
	fill(cnt, cnt + n, -1);
	for (int i = 0; i < k; ++i) {
		cin >> items[i];
		if (cnt[items[i] == -1])
			cnt[items[i]] = 1;
		else
			cnt[items[i]]++;
	}
	// 멀티탭에 먼저 넣고
	for (int i = 0; i < n; ++i) {
		multitab[i] = items[i];
		is_there[items[i]] = 1;
		cnt[items[i]]--;
	}
	// 뽑고 꽂기 진행
	int ans = 0;
	for (int i = n; i < k; ++i) {
		cnt[items[i]]--;
		if (is_there[items[i]]) continue;
		int idx = find_lowest_idx();
		multitab[idx] = items[i];
		is_there[items[i]] = 1;
		ans++;
	}
	cout << ans;
}
