#include <iostream>

using namespace std;

int f(int r, int c, int n) {
	int half = 1 << (n - 1);

	if (n == 0) return 0;

	if (r < half && c < half) return f(r, c, n - 1);
	if (r < half && c >= half) return half * half + f(r, c - half, n - 1);
	if (r >= half && c < half) return 2 * half * half + f(r - half, c, n - 1);
	return 3 * half * half + f(r - half, c - half, n - 1);
}

int main(void) {
	int n, r, c;

	cin >> n >> r >> c;
	cout << f(r, c, n);
}
