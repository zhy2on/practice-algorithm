#include <bits/stdc++.h>
using namespace std;

int circle[4][8];
int r[4];

void rotate() {
	for (int idx = 0; idx < 4; ++idx) {
		if (r[idx] == 0) continue;

		if (r[idx] == 1) {
			int tmp = circle[idx][7];
			for (int i = 7; i > 0; --i) circle[idx][i] = circle[idx][i - 1];
			circle[idx][0] = tmp;
		} else {
			int tmp = circle[idx][0];
			for (int i = 0; i < 7; ++i) circle[idx][i] = circle[idx][i + 1];
			circle[idx][7] = tmp;
		}
	}
}

void run() {
	int idx;

	fill(r, r + 4, 0);
	cin >> idx >> r[--idx];

	// left
	for (int i = idx; i > 0; --i) {
		if (circle[i][6] == circle[i - 1][2]) break;
		r[i - 1] = r[i] * -1;
	}
	// right
	for (int i = idx; i < 3; ++i) {
		if (circle[i][2] == circle[i + 1][6]) break;
		r[i + 1] = r[i] * -1;
	}

	rotate();
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 8; ++j) {
			char c;
			cin >> c;
			circle[i][j] = c - '0';
		}
	}

	int k;
	cin >> k;
	while (k--) run();

	int ans = 0;
	for (int i = 0; i < 4; ++i) ans += circle[i][0] * (1 << i);
	cout << ans;
}
