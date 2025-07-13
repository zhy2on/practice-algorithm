#include <bits/stdc++.h>
using namespace std;

int circle[4][8];

void run() {
	int idx, r[4] = {};

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

	for (int i = 0; i < 4; ++i) {
		if (r[i] == 1)
			rotate(circle[i], circle[i] + 7, circle[i] + 8);
		else if (r[i] == -1)
			rotate(circle[i], circle[i] + 1, circle[i] + 8);
	}
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
