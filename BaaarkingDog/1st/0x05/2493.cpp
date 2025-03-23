#include <iostream>
#include <stack>

using namespace std;

#define X first
#define Y second

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	stack<pair<int, int> > s;
	s.push({100000001, 0});

	for (int i = 1; i <= N; ++i) {
		int height;
		cin >> height;

		while (s.top().X < height) s.pop();

		cout << s.top().Y << " ";
		s.push({height, i});
	}
}
