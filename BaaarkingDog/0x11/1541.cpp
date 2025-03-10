#include <bits/stdc++.h>
using namespace std;

string str;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	int tmp = 0, multi = 1, ans = 0;
	for (char c : str) {
		if (c >= '0' && c <= '9')
			tmp = tmp * 10 + c - '0';
		else {
			ans += tmp * multi;
			tmp = 0;
			if (multi == 1 && c == '-') multi = -1;
		}
	}
	ans += tmp * multi;
	cout << ans;
}
