#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;
	int cnt = 1;
	int n;
	cin >> n;

	string ans;
	while (n--) {
		int k;
		cin >> k;

		while (cnt <= k) {
			s.push(cnt++);
			ans += "+\n";
		}
		if (s.top() != k) {
			cout << "NO\n";
			return 0;
		}
		s.pop();
		ans += "-\n";
	}

	cout << ans;
}
