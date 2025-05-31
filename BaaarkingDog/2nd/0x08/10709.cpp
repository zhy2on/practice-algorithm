#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	stack<char> s;
	int ans = 0;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '(')
			s.push(str[i]);
		else {
			s.pop();
			if (i > 0 && str[i - 1] == ')')
				++ans;
			else
				ans += s.size();
		}
	}
	cout << ans;
}
