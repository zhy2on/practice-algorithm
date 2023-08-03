#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	string str;
	stack<char> s;
	bool flag;

	while (true) {
		flag = true;
		while (!s.empty()) s.pop();

		getline(cin, str);
		if (str == ".") break;

		for (int i = 0; i < str.length(); ++i) {
			if (str[i] == '(' || str[i] == '[')	s.push(str[i]);
			else if (str[i] == ')' || str[i] == ']') {
				if (s.empty()) {
					flag = false;
					break;
				} else {
					if (str[i] == ')' && s.top() == '(') s.pop();
					else if (str[i] == ']' && s.top() == '[') s.pop();
					else break;
				}
			}
		}
		if (s.empty() && flag) cout << "yes\n";
		else cout << "no\n";
	}

}
