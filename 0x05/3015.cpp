#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	stack<pair<int, int> > s;
	long long ans = 0;
	while (n--) {
		int now;
		cin >> now;
		int cnt = 1;
		while (!s.empty() && s.top().first <= now) {
			ans += s.top().second;
			if (s.top().first == now) cnt += s.top().second;
			s.pop();
		}
		ans += !s.empty();
		s.push(make_pair(now, cnt));
	}

	cout << ans;
}
