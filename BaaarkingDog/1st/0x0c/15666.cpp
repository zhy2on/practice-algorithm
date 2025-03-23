#include <iostream>
#include <algorithm>

using namespace std;

int N, M, arr[8], ans[8], cnt;
bool exist[10000];

void dfs(int k, int st) {
	if (k == M) {
		for (int i = 0; i < k; ++i) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i < cnt; ++i) {
		ans[k] = arr[i];
		dfs(k + 1, i);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		if (!exist[tmp - 1]) {
			arr[cnt++] = tmp;
			exist[tmp - 1] = 1;
		}
	}
	sort(arr, arr + cnt);
	dfs(0, 0);
}
