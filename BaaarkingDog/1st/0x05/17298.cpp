#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int k[1000000];
	int ans[1000000];
	stack<int> s;

	for (int i = 0; i < N; ++i) cin >> k[i];

	for (int i = N - 1; i >= 0; --i) {
		while (!s.empty() && s.top() <= k[i]) s.pop();
		if (s.empty())
			ans[i] = -1;
		else
			ans[i] = s.top();
		s.push(k[i]);
	}

	for (int i = 0; i < N; ++i) cout << ans[i] << " ";
}
