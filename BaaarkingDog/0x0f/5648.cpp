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
		reverse(str.begin(), str.end());
		arr[i] = stoll(str);
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; ++i) cout << arr[i] << '\n';
}
