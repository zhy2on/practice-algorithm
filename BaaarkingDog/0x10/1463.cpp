#include <algorithm>
#include <iostream>

using namespace std;

int d[1000005];
int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	d[1] = 0;

	for (int i = 2; i <= N; ++i) {
		d[i] = d[i - 1];
		if (i % 2 == 0) d[i] = min(d[i / 2], d[i]);
		if (i % 3 == 0) d[i] = min(d[i / 3], d[i]);
		d[i] += 1;
	}

	cout << d[N];
}
