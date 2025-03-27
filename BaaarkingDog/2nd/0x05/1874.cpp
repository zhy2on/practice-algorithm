#include <bits/stdc++.h>
using namespace std;

stack<int> s;
string ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	int cnt = 1;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;

		while (cnt <= k) {
			s.push(cnt++);
			ans += "+\n";
		}
		if (s.top() != k) {
			cout << "NO";
			return 0;
		}
		s.pop();
		ans += "-\n";
	}

	cout << ans;
}
