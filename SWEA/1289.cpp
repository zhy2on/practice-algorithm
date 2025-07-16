#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		string str;
		cin >> str;

		int cnt = 0;
		if (str[0] == '1') ++cnt;
		for (int i = 1; i < str.length(); ++i) {
			if (str[i] != str[i - 1]) ++cnt;
		}
		cout << '#' << t << ' ' << cnt << '\n';
	}
}
