#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

#define student tuple<string, int, int, int>

bool comp(const student &a, const student &b) {
	if (get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);
	if (get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
	if (get<3>(a) != get<3>(b)) return get<3>(a) > get<3>(b);
	return get<0>(a) < get<0>(b);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	student arr[100001];
	for (int i = 0; i < N; ++i) {
		int a, b, c;
		string s;
		cin >> s >> a >> b >> c;
		arr[i] = {s, a, b, c};
	}
	sort(arr, arr + N, comp);
	for (int i = 0; i < N; ++i) cout << get<0>(arr[i]) << '\n';
}
