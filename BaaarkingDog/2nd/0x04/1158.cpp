#include <bits/stdc++.h>
using namespace std;

int num[5001];
int cnt;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	list<int> L;
	for (int i = 1; i <= n; ++i) L.push_back(i);
	auto it = L.begin();
	while (!L.empty()) {
		for (int i = 0; i < k - 1; ++i) {
			++it;
			if (it == L.end()) it = L.begin();
		}
		num[cnt++] = *it;
		it = L.erase(it);
		if (it == L.end()) it = L.begin();
	}

	cout << '<';
	for (int i = 0; i < n - 1; ++i) cout << num[i] << ", ";
	cout << num[n - 1] << '>';
}
