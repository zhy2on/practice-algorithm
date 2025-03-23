#include <iostream>
#include <algorithm>
using namespace std;

int T, N, M;
int a[20001], b[20001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		int cnt = 0;
		cin >> N >> M;
		for (int i = 0; i < N; ++i) cin >> a[i];
		for (int i = 0; i < M; ++i) cin >> b[i];
		sort(a, a + N);
		sort(b, b + M);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M && a[i] > b[j]; ++j) {
				++cnt;
			}
		}
		cout << cnt << '\n';
	}
}
