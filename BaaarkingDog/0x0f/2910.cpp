#include <iostream>
#include <algorithm>
using namespace std;

int N, C;
pair<int, int> arr[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> C;
	for (int i = 0; i < N; ++i) {
		int k;
		cin >> k;
		int j;
		for (j = 0; j < i; ++j) {
			if (arr[j].first == k) {
				++arr[j].second;
				break;
			}
		}
		if (j == i) arr[j] = {k, 1};
	}
	for (int i = N - 1; i >= 0; --i) {
		for (int j = 0; j < N; ++j) {
			if (arr[j].second == i) {
				while (arr[j].second--) cout << arr[j].first << ' ';
			}
		}
	}
}
