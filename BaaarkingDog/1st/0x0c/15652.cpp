#include <iostream>

using namespace std;

int N, M, arr[8];

void dfs(int k) {
	if (k == M) {
		for (int i = 0; i < k; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (k > 0 && arr[k - 1] > i + 1) continue;
		arr[k] = i + 1;
		dfs(k + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	dfs(0);
}
