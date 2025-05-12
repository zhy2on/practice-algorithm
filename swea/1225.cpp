#include <bits/stdc++.h>
using namespace std;

int nums[8];

int get_ans() {
	int cur = 0;
	int minus_cnt = 0;

	while (1) {
		nums[cur] -= minus_cnt + 1;
		if (nums[cur] <= 0) {
			nums[cur] = 0;
			return cur + 1;
		}
		cur = (cur + 1) % 8;
		minus_cnt = (minus_cnt + 1) % 5;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; ++i) {
		int tt;
		cin >> tt;

		for (int j = 0; j < 8; ++j) {
			int n;
			cin >> n;
			nums[j] = n;
		}

		cout << '#' << tt << ' ';
		int cur = get_ans();
		for (int j = 0; j < 8; ++j) {
			cout << nums[cur % 8] << ' ';
			cur++;
		}
		cout << '\n';
	}
}

/*
1
9550 9556 9550 9553 9558 9551 9551 9551
*/
