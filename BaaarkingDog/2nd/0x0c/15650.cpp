#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vector<int> a;
	for (int i = 0; i < n; ++i) a.push_back(i < m ? 0 : 1);

	do {
		for (int i = 0; i < n; ++i) {
			if (a[i] == 0) cout << i + 1 << ' ';
		}
		cout << '\n';
	} while (next_permutation(a.begin(), a.end()));
}
