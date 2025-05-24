#include <bits/stdc++.h>
using namespace std;

void delete_nums(vector<int> &v) {
	int index, count;
	cin >> index >> count;
	v.erase(v.begin() + index, v.begin() + index + count);
}

void insert_nums(vector<int> &v) {
	int index, count;
	cin >> index >> count;

	int arr[21];
	for (int i = 0; i < count; ++i) cin >> arr[i];
	v.insert(v.begin() + index, arr, arr + count);
}

void edit_password(vector<int> &v) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char cmd;
		cin >> cmd;
		if (cmd == 'I') {
			insert_nums(v);
		} else {
			delete_nums(v);
		}
	}
}

void get_password(vector<int> &v) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
}

int main(void) {
	for (int t = 0; t < 10; ++t) {
		vector<int> v;
		get_password(v);
		edit_password(v);

		// 출력
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
