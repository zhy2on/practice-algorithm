#include <iostream>

using namespace std;

int n, ans;

#define MAX 15

bool v1[MAX - 1];
bool v2[2 * MAX - 1];
bool v3[2 * MAX - 1];

void f(int r) {
	if (r == n) {
		++ans;
		return;
	}

	for (int c = 0; c < n; ++c) {
		if (v1[c] || v2[r + c] || v3[r - c + n - 1]) continue;
		v1[c] = 1;
		v2[r + c] = 1;
		v3[r - c + n - 1] = 1;
		f(r + 1);
		v1[c] = 0;
		v2[r + c] = 0;
		v3[r - c + n - 1] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	f(0);

	cout << ans;
}
