#include <bits/stdc++.h>
using namespace std;

const string NUMBER_STRINGS[10] = {"ZRO", "ONE", "TWO", "THR", "FOR",
								   "FIV", "SIX", "SVN", "EGT", "NIN"};
unordered_map<string, int> STRING_TO_NUM;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; ++i) {
		STRING_TO_NUM[NUMBER_STRINGS[i]] = i;
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		string t_num;
		int n;

		cin >> t_num >> n;

		int n_count[10];

		cout << t_num << '\n';
		fill(n_count, n_count + 10, 0);
		for (int j = 0; j < n; ++j) {
			string str;
			cin >> str;
			n_count[STRING_TO_NUM[str]]++;
		}

		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < n_count[j]; ++k) {
				cout << NUMBER_STRINGS[j] << ' ';
			}
		}
		cout << '\n';
	}
}

/*
10
#1 15
SVN FOR ZRO NIN FOR EGT EGT TWO FOR FIV FIV ONE SVN ONE ONE
*/
