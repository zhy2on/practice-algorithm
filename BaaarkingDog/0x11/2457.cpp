#include <bits/stdc++.h>
using namespace std;

pair<int, int> date[100001];
int n;
int t = 3001;

int find_next_index(int index) {
	for (int i = index; i < n; ++i) {
		if (date[i].second <= t) index = i;
	}
	return index;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		// sort를 위해 end부터 저장
		date[i].second = a * 1000 + b;
		date[i].first = c * 1000 + d;
	}

	sort(date, date + n);

	int ans = 0, i = 0, next_i;
	while (date[i].first <= 11030) {
		next_i = find_next_index(i);
		if (next_i == i) {
			cout << 0;
			return 0;
		}
		t = date[next_i].first;
		i = next_i;
		ans += 1;
	}

	cout << ans;
}
