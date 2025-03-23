#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

#define student tuple<int, int, int, string>

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
		arr[i] = {-a, b, -c, s};
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; ++i) cout << get<3>(arr[i]) << '\n';
}
