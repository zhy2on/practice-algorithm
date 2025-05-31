#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int ans = 0;
	while (n--) {
		string str;
		cin >> str;

		stack<char> s;
		for (auto c : str) {
			if (!s.empty() && s.top() == c)
				s.pop();
			else
				s.push(c);
		}
		if (s.empty()) ++ans;
	}
	cout << ans;
}
