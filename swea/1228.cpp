#include <bits/stdc++.h>
using namespace std;

void solve(list<int> &l) {
	char c;
	int index;
	int count;

	cin >> c >> index >> count;
	stack<int> s;
	for (int i = 0; i < count; ++i) {
		int n;
		cin >> n;
		s.push(n);
	}

	for (int i = 0; i < count; ++i) {
		int n = s.top();
		s.pop();
		auto it = l.begin();
		for (int j = 0; j < index; ++j) it++;
		l.insert(it, n);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; ++i) {
		int n;
		cin >> n;
		list<int> l;
		for (int j = 0; j < n; ++j) {
			int k;
			cin >> k;
			if (i < 10) l.push_back(k);
		}
		int tt;
		cin >> tt;
		for (int j = 0; j < tt; ++j) solve(l);
		cout << '#' << i + 1 << ' ';
		auto it = l.begin();
		for (int j = 0; j < 10; ++j) cout << *it++ << ' ';
		cout << '\n';
	}
}

/*
11
449047 855428 425117 532416 358612 929816 313459 311433 472478 589139 568205
7
I 1 5 400905 139831 966064 336948 119288 I 8 6 436704 702451 762737 557561
810021 771706 I 3 8 389953 706628 552108 238749 661021 498160 493414 377808 I 13
4 237017 301569 243869 252994 I 3 4 408347 618608 822798 370982 I 8 2 424216
356268 I 4 10 512816 992679 693002 835918 768525 949227 628969 521945 839380
479976
*/
