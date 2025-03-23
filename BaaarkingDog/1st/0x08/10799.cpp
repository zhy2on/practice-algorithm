#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;

	cin >> str;
	int cnt = 0;
	int res = 0;

	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '(') {
			++cnt;
		} else if (str[i] == ')') {
			--cnt;
			if (str[i - 1] == '(') {
				res += cnt;
			} else {
				++res;
			}
		}
	}

	cout << res;
}
