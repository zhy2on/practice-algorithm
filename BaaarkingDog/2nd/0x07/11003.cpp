#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

deque<pair<int, int> > dq;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;

		if (!dq.empty() && dq.front().Y < i - L + 1) dq.pop_front();
		while (!dq.empty() && dq.back().X >= x) dq.pop_back();
		dq.push_back({x, i});
		cout << dq.front().X << ' ';
	}
}
