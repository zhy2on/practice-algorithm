#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;

	cin >> str;

	int multi = 1, div = 1, res = 0;
	bool close = false;
	stack<char> s;

	for (auto c : str) {
		if (c == '(' || c == '[') {
			if (close) {
				res += multi;
				multi /= div;
				div = 1;
			}
			c == '(' ? multi *= 2 : multi *= 3;
			close = false;
			s.push(c);
		} else {
			if (s.empty()) {
				res = 0;
				multi = 0;
				break;
			}
			close = true;

			if (c == ')' && s.top() == '(') {
				div *= 2;
				s.pop();
			} else if (c == ']' && s.top() == '[') {
				div *= 3;
				s.pop();
			} else {
				res = 0;
				multi = 0;
				break;
			}
		}
	}

	res += multi;

	if (!s.empty()) res = 0;
	cout << res;
}
