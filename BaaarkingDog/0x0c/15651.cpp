#include <iostream>

using namespace std;

int N, M, arr[7];

void dfs(int k) {
	if (k == M) {
		for (int i = 0; i < M; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; ++i) {
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
