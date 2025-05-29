#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
bool is_front;

void print() {
	cout << '[';
	for (int i = 0; i < dq.size(); ++i) {
		if (is_front)
			cout << dq[i];
		else
			cout << dq[dq.size() - 1 - i];
		if (i == dq.size() - 1) break;
		cout << ',';
	}
	cout << "]\n";
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

void fill_dq(string numbers) {
	dq.clear();
	is_front = 1;

	int x = 0;
	for (auto c : numbers) {
		if (isdigit(c)) {
			x = x * 10 + c - '0';
		} else if (c == ',' || c == ']') {
			if (x < 1) continue;
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

		fill_dq(numbers);
		run(cmd);
	}
}
