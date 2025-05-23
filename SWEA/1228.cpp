#include <bits/stdc++.h>
using namespace std;

void solve_case(int t) {
	int n;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	int c;
	cin >> c;
	for (int i = 0; i < c; ++i) {
		char cmd;
		int index, count;
		cin >> cmd >> index >> count;
		vector<int> insert_v;
		for (int j = 0; j < count; ++j) {
			int tmp;
			cin >> tmp;
			insert_v.push_back(tmp);
		}
		v.insert(v.begin() + index, insert_v.begin(), insert_v.end());
	}

	cout << '#' << t << ' ';
	for (int i = 0; i < 10; ++i) cout << v[i] << ' ';
	cout << '\n';
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int t = 0; t < 10; ++t) {
		solve_case(t + 1);
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
