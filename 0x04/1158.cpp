#include <iostream>
#include <list>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	list<int> L;
	for (int i = 1; i <= N; ++i) L.insert(L.end(), i);

	cout << "<";
	int i = 0;
	auto it = L.begin();
	while (!L.empty()) {
		for (it = L.begin(); it != L.end(); ++it) {
			++i;
			if (i % K == 0) {
				cout << *it;
				if (i / K < N) cout << ", ";
				else cout << ">";
				it = --L.erase(it);
			}
		}
	}

	return 0;
}
