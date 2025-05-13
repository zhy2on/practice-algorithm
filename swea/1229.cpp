#include <bits/stdc++.h>

using namespace std;

void delete_nums(vector<int> &original_v) {
	int index, count;
	cin >> index >> count;
	original_v.erase(original_v.begin() + index,
					 original_v.begin() + index + count);
}

void insert_nums(vector<int> &original_v) {
	int index, count;
	cin >> index >> count;

	vector<int> v;
	for (int i = 0; i < count; ++i) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	original_v.insert(original_v.begin() + index, v.begin(), v.end());
}

void solve_case(vector<int> &v) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	int cmd_n;
	cin >> cmd_n;
	for (int i = 0; i < cmd_n; ++i) {
		char cmd;
		cin >> cmd;
		if (cmd == 'I')
			insert_nums(v);
		else
			delete_nums(v);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int t = 0; t < 10; ++t) {
		vector<int> v;
		solve_case(v);
		cout << '#' << t + 1 << ' ';
		for (int i = 0; i < 10; ++i) cout << v[i] << ' ';
		cout << '\n';
	}
}

/*
11
701633 517247 207227 598906 709204 177422 933135 361253 641488 272037 700207
3
I 1 4 281822 746265 450734 108373 I 2 9 666218 302034 208501 648283 798327
631226 998665 959675 852007 D 3 1
*/
