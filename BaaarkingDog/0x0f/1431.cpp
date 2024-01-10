#include <iostream>
#include <algorithm>
using namespace std;

int N;
string arr[51];

bool comp_length(const string &a, const string &b) {
	return a.length() < b.length();
}

bool comp_cnt(const string &a, const string &b) {
	int acnt = 0, bcnt = 0;
	for (auto c : a) {
		if (c >= '0' && c <= '9') acnt += c - '0';
	}
	for (auto c : b) {
		if (c >= '0' && c <= '9') bcnt += c - '0';
	}
	return acnt < bcnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];

	sort(arr, arr + N);
	stable_sort(arr, arr + N, comp_cnt);
	stable_sort(arr, arr + N, comp_length);

	for (int i = 0; i < N; ++i) cout << arr[i] << '\n';
}
