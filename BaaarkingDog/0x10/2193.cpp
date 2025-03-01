#include <iostream>
using namespace std;

long d[91][2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	d[1][1] = 1;

	int N;
	cin >> N;
	for (int i = 2; i <= N; ++i) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
	cout << d[N][0] + d[N][1];
}
