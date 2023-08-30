#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	int N;

	cin >> N;

	int cnt = 0;
	while (N--) {
		string str;
		stack<int> s;

		cin >> str;
		
		for (auto c : str) {
			if (s.empty() || s.top() != c) s.push(c);
			else s.pop();
		}
		if (s.empty()) ++cnt;
	}

	cout << cnt;

}
