#include <iostream>
#include <algorithm>
using namespace std;

int N;
string arr[51];

bool comp(const string &a, const string &b) {
	int alen = a.length(), blen = b.length();
	int acnt = 0, bcnt = 0;
	if (alen != blen) return alen < blen;
	for (auto c : a) if (c >= '0' && c <= '9') acnt += c - '0';
	for (auto c : b) if (c >= '0' && c <= '9') bcnt += c - '0';
	if (acnt != bcnt) return acnt < bcnt;
	return a < b;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	sort(arr, arr + N, comp);
	for (int i = 0; i < N; ++i) cout << arr[i] << '\n';
}
