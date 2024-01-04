#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	pair<int, int> arr[100001];
	for (int i = 0; i < N; ++i) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	for (int i = 0; i < N; ++i) cout << arr[i].first << ' ' << arr[i].second << '\n';
}
