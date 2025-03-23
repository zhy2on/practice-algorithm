#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

pair<int, int> num[1000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i].X >> num[i].Y;
	}

	sort(num, num + n);
	int preX = num[0].X, preY = num[0].Y;
	long long ans = 0;
	for (int i = 1; i < n; ++i) {
		if (num[i].X > preY) {
			ans += preY - preX;
			preX = num[i].X;
			preY = num[i].Y;
		} else if (num[i].Y > preY)
			preY = num[i].Y;
	}
	ans += preY - preX;
	cout << ans;
}
