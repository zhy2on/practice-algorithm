#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		string str;
		list<char> pwd;
		auto cursor = pwd.end();
	
		cin >> str;
	
		for (auto c : str) {
			if (c == '<') {
				if (cursor != pwd.begin()) --cursor;
			}
			else if (c == '>') {
				if (cursor != pwd.end()) ++cursor;
			}
			else if (c == '-') {
				if (cursor != pwd.begin()) {
					--cursor;
					cursor = pwd.erase(cursor);
				}
			}
			else {
				pwd.insert(cursor, c);
			}
		}
		
		for (auto p : pwd) cout << p;
		cout << '\n';
	}
}