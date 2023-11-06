#include <iostream>
#include <algorithm>

using namespace std;

int N, M, arr[10];
bool vis[10];

void p(int idx, int k) {
	if (k == M) {
		for (int i = 0; i < k; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = idx; i < N; ++i) {
		if (vis[i]) continue;
		arr[k] = i + 1;
		vis[i] = 1;
		p(i + 1, k + 1);
		vis[i] = 0;
	}
}

int main(void) {
	cin >> N >> M;

	p(0, 0);
}

/* next_permutation ver.
int main(void) {
	cin >> N >> M;

	for (int i = M; i < N; ++i) arr[i] = 1;

	do {
		for (int i = 0; i < N; ++i) {
			if (!arr[i]) cout << i + 1 << ' ';
		}
		cout << '\n';
	} while(next_permutation(arr, arr + N));
}
*/