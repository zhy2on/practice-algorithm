#include <bits/stdc++.h>
using namespace std;

const string number[10] = {"ZRO", "ONE", "TWO", "THR", "FOR",
						   "FIV", "SIX", "SVN", "EGT", "NIN"};

int which_num(string str) {
	int i;
	for (i = 0; i < 10; ++i) {
		if (number[i] == str) break;
	}
	return i;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		string t_num;
		int n;

		cin >> t_num >> n;

		int ns[100000];

		for (int j = 0; j < n; ++j) {
			string str;
			cin >> str;
			ns[j] = which_num(str);
		}

		sort(ns, ns + n);

		cout << t_num << '\n';
		for (int j = 0; j < n; ++j) {
			cout << number[ns[j]] << ' ';
		}
		cout << '\n';
	}
}

/*
10
#1 15
SVN FOR ZRO NIN FOR EGT EGT TWO FOR FIV FIV ONE SVN ONE ONE
*/
