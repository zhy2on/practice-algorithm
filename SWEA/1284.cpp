#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int t;
	cin >> t;

	for (int t_c = 1; t_c <= t; ++t_c) {
		int p, q, r, s, w;
		cin >> p >> q >> r >> s >> w;

		int a = w * p;
		int b;
		if (w < r)
			b = q;
		else
			b = q + (w - r) * s;
		cout << '#' << t_c << ' ' << min(a, b) << '\n';
	}
}
