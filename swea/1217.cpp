#include <iostream>

using namespace std;

long get_n_sqaure_m(int n, int m) {
	if (m == 1) return n;
	return n * get_n_sqaure_m(n, --m);
}

int main(void) {
	for (int i = 0; i < 10; ++i) {
		int t;
		cin >> t;

		int n, m;
		cin >> n >> m;
		cout << '#' << t << ' ' << get_n_sqaure_m(n, m) << '\n';
	}
}
