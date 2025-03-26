#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		list<char> L;
		string str;
		auto it = L.begin();

		cin >> str;
		for (auto c : str) {
			if (c == '<') {
				if (it != L.begin()) --it;
			} else if (c == '>') {
				if (it != L.end()) ++it;
			} else if (c == '-') {
				if (it != L.begin()) it = L.erase(--it);
			} else
				L.insert(it, c);
		}
		for (auto c : L) cout << c;
		cout << '\n';
	}
}
