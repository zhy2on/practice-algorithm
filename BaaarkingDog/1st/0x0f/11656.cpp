#include <iostream>
#include <algorithm>

using namespace std;

string arr[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	size_t len = str.length();
	for (int i = 0; i < len; ++i) arr[i] = str.substr(i, len);
	sort(arr, arr + len);
	for (int i = 0; i < len; ++i) cout << arr[i] << '\n';
}
