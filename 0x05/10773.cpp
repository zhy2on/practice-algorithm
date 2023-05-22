#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K, n;
	stack<int> S;

	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> n;
		if (n == 0) S.pop();
		else S.push(n);
	}
	n = 0;
	while (!S.empty()) {
		n += S.top();
		S.pop();
	}
	cout << n;
}
