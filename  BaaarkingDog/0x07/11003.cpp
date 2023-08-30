#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, L;

	cin >> N >> L;

	deque<pair<int, int> > dq;
	int *res = new int[N];

	for (int i = 0; i < N; ++i) {
		int x;

		cin >> x;

		while (!dq.empty() && dq.back().first >= x) dq.pop_back();

		dq.push_back(make_pair(x, i));
		res[i] = dq.front().first;

		if (dq.front().second == i - L + 1) dq.pop_front();
	}

	for (int i = 0; i < N - 1; ++i) cout << res[i] << " ";
	cout << res[N - 1];
}
