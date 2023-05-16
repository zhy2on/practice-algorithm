#include <iostream>
#include <list>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string init;
	cin >> init;
	list<char> L;
	// 범위기반 for문 - index가 없다. elem이라는 변수에 배열의 요소가 복사되기 때문에 직접적으로
	// 값을 업데이트 할 수 없다.
	for (auto c : init) L.push_back(c);
	auto cursor = L.end(); // return list iterator

	int q;
	cin >> q;
	while (q--) {
		char op;
		cin >> op;

		if (op == 'P') {
			char add;
			cin >> add;
			L.insert(cursor, add);
		}
		else if (op == 'L') {
			if (cursor != L.begin()) cursor--;
		}
		else if (op == 'D') {
			if (cursor != L.end()) cursor++;
		}
		else if (op == 'B') {
			if (cursor != L.begin()) {
				cursor--;
				cursor = L.erase(cursor);
			}
		}
	}
	for (auto c : L) cout << c;
}
