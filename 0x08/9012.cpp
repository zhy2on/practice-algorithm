#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	while (n--) {
		string str;
		stack<char> s;
		bool flag = true;

		cin >> str;

		for (auto c : str) {
			if (c == '(') s.push(c);
			else if (c == ')') {
				if (s.empty()) flag = false;
				else if (s.top() == '(') s.pop();
				else break;
			}
		}
		if (s.empty() && flag) cout << "YES\n";
		else cout << "NO\n";
	}
}
