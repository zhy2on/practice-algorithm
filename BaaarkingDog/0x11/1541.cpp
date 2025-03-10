#include <bits/stdc++.h>
using namespace std;

string str;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	int tmp = 0, multi = 1, ans = 0;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] >= '0' && str[i] <= '9')
			tmp = tmp * 10 + str[i] - '0';
		else {
			ans += tmp * multi;
			tmp = 0;
			if (multi == 1 && str[i] == '-') multi = -1;
		}
	}
	ans += tmp * multi;
	cout << ans;
}
