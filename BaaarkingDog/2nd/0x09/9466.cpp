#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int s[1000001], vis[1000001], n;

		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> s[i];
			vis[i] = -1;
		}

		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			int cur = i;
			while (1) {
				if (vis[cur] == 1) break;
				++vis[cur];
				cur = s[cur];
			}

			for (int j = 1; j <= n; ++j) {
				if (!vis[j]) {
					++ans;
					vis[j] = 1;
				}
			}
		}
		cout << ans << '\n';
	}
}

/*
1 2 3 4 5
3 4 2 5 4
*/
