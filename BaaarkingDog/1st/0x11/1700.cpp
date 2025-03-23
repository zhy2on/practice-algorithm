#include <bits/stdc++.h>
using namespace std;

int n, k;
int items[101], multitab[101];
bool is_there[101];

int find_farthest(int cur) {
	int max_future = -1;  // 가장 나중에 나오는 시점
	int max_idx = 0;	  // 그 아이템의 멀티탭 인덱스

	for (int i = 0; i < n; ++i) {
		// 멀티탭에 꽂힌 것 중 가장 나중에 나오는 것을 선택
		int next_occur = k + 1;	 // 초기값은 아예 안 나오는 경우. 그래서 K + 1.
		for (int j = cur + 1; j <= k; ++j) {
			if (multitab[i] == items[j]) {
				next_occur = j;
				break;
			}
		}
		if (next_occur > max_future) {
			max_future = next_occur;
			max_idx = i;
		}
	}
	return max_idx;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> items[i];
	}
	int ans = 0, cnt = 0;
	for (int i = 1; i <= k; ++i) {
		if (is_there[items[i]]) continue;  // 이미 꽂혀 있으면 그냥 지나가기
		if (cnt < n) {					   // 멀티탭에 자리가 있으면 꽂기
			multitab[cnt] = items[i];
			is_there[items[i]] = 1;
			++cnt;
			continue;
		}
		// 없으면 제일 나중에 나오는 것을 뽑음
		int idx = find_farthest(i);
		is_there[multitab[idx]] = 0;
		multitab[idx] = items[i];
		is_there[items[i]] = 1;
		++ans;
	}
	cout << ans;
}
