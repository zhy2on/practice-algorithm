#include <iostream>

using namespace std;
using ll = long long;

ll f(ll a, ll b, ll c) {
	if (b == 1) return a % c;
	ll y = f(a, b / 2, c);
	y = y * y % c;
	if (b % 2 == 0) return y;
	return y * a % c;
}

int main(void) {
	ll a, b, c;

	cin >> a >> b >> c;

	cout << f(a, b, c);
}
