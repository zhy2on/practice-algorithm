#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
long long ans = 0;
int N;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--) {
		long long height;
		cin >> height;
		while (!s.empty() && (s.top() < height))
			s.pop();
		ans += s.size();
		s.push(height);
	}
	cout << ans;
}
