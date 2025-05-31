#include <bits/stdc++.h>
using namespace std;

bool is_match(char a, char b) {
	return (a == '[' && b == ']') || (a == '(' && b == ')');
}

bool is_open(char c) { return c == '[' || c == '('; }

int multi(char c) {
	if (c == '[' || c == ']') return 3;
	if (c == '(' || c == ')') return 2;
	return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	stack<char> s;
	int ans = 0, value = 1;
	for (int i = 0; i < str.length(); ++i) {
		// open이면 multi 곱하고 stack에 push
		if (is_open(str[i])) {
			value *= multi(str[i]);
			s.push(str[i]);
		} else {  // 닫기이면
			if (s.empty() ||
				!is_match(s.top(), str[i])) {  // 올바르지 않으면 0 리턴
				cout << '0';
				return 0;
			} else {
				if (is_match(str[i - 1], str[i]))
					ans += value;  // 맞쌍이면 ans 업데이트
				value /= multi(str[i]);
				s.pop();
			}
		}
	}
	if (!s.empty())	 // ()( 인 경우를 거르기 위함
		cout << '0';
	else
		cout << ans;
}
