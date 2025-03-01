#include <bits/stdc++.h>
using namespace std;

long arr[100001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	long maxx = -1001;
	long tmp = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		tmp += arr[i];
		if (tmp > maxx) maxx = tmp;
		if (tmp < 0) tmp = 0;
	}
	cout << maxx;
}
