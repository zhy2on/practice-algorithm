#include <iostream>
#include <algorithm>
using namespace std;

int N;
string arr[20001];

bool comp(const string &a, const string &b) {
	int alen = a.size(), blen = b.size();
	if (alen != blen) return alen < blen;
	return a < b;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	sort(arr, arr + N, comp);
	for (int i = 0; i < N; ++i) {
		if (i == 0 || arr[i] != arr[i - 1]) cout << arr[i] << '\n';
	}
}
