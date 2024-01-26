#include <iostream>
#include <algorithm>

using namespace std;

#define member pair<int, string>
int N;
member arr[100001];

bool comp(const member &a, const member &b) {
	return a.first < b.first;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i].first >> arr[i].second;
	stable_sort(arr, arr + N, comp);
	for (int i = 0; i < N; ++i) cout << arr[i].first << ' ' << arr[i].second << '\n';
}
