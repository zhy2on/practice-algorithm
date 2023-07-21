#include <iostream>
#include <deque>

using namespace std;

deque<int> dq, bq;

void left_rotate(int x) {
	while (dq.front() != x) {
		dq.push_back(dq.front());
		dq.pop_front();
	}
	dq.pop_front();
}

void right_rotate(int x) {
	while (dq.front() != x) {
		dq.push_front(dq.back());
		dq.pop_back();
	}
	dq.pop_front();
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		dq.push_back(i);
	}

	int res = 0;
	while (m--) {
		int x, cnt;
		cin >> x;

		bq = dq;
		cnt = 0;
		while (bq.front() != x) {
			bq.push_back(bq.front());
			bq.pop_front();
			++cnt;
		}
		if (cnt < bq.size() / 2 + 1) {
			left_rotate(x);
			res += cnt;
		} else {
			right_rotate(x);
			res += (dq.size() - cnt + 1);
		}
	}

	cout << res;
}
