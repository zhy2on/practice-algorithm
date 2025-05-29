#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
bool is_front;

void print() {
	if (dq.empty()) {
		cout << "[]\n";
		return;
	}
	cout << '[';
	if (is_front) {
		while (dq.size() > 1) {
			cout << dq.front() << ',';
			dq.pop_front();
		}
	} else {
		while (dq.size() > 1) {
			cout << dq.back() << ',';
			dq.pop_back();
		}
	}
	cout << dq.front() << "]\n";
}

void run(string cmd) {
	for (auto c : cmd) {
		if (c == 'R')
			is_front = !is_front;
		else {
			if (dq.empty()) {
				cout << "error\n";
				return;
			}
			if (is_front)
				dq.pop_front();
			else
				dq.pop_back();
		}
	}
	print();
}

void fill_dq(string str) {
	int x = 0;
	for (auto c : str) {
		if (isdigit(c)) {
			x = x * 10 + c - '0';
		} else if (c == ',' || c == ']') {
			dq.push_back(x);
			x = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 4
	int T;
	cin >> T;

	while (T--) {
		// RDD
		string cmd;
		cin >> cmd;

		// 4
		int n;
		cin >> n;

		// [1,2,3,4]
		string numbers;
		cin >> numbers;
		dq.clear();
		is_front = 1;
		if (n > 0) fill_dq(numbers);
		run(cmd);
	}
}
