#include <bits/stdc++.h>
using namespace std;

void print(int r, int c, int n) {
	if ((r / n) % 3 == 1 && (c / n) % 3 == 1) {
		cout << ' ';
		return;
	}

	if (n == 1) {
		cout << '*';
		return;
	}

	print(r, c, n / 3);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			print(i, j, n / 3);
		}
		cout << '\n';
	}
}
