#include <bits/stdc++.h>
using namespace std;

long p[101];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	fill(p + 1, p + 4, 1);
	fill(p + 4, p + 6, 2);
	p[6] = 3;
	p[7] = 4;
	p[8] = 5;
	for (int i = 9; i <= 100; ++i) {
		p[i] = p[i - 1] + p[i - 5];
	}
	for (int i = 0; i < t; ++i) {
		cin >> n;
		cout << p[n] << '\n';
	}
}
