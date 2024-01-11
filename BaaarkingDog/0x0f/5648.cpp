#include <algorithm>
#include <iostream>
using namespace std;

int N;
long long arr[1000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		int len = str.size();
		for (int j = 0; j < len / 2; ++j) {
			swap(str[j], str[len - 1 - j]);
		}
		arr[i] = stol(str);
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; ++i) cout << arr[i] << '\n';
}
