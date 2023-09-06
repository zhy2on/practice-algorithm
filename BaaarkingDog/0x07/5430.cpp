#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

void fill_dq(string str) {
	int n = 0;

	if (str[0] == '[' && str[1] ==']') return;

	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '[') continue;
		if (str[i] == ',' || str[i] == ']') {
			dq.push_back(n);
			n = 0;
			continue;
		}
		n = n * 10 + str[i] - '0';
	}
}

void print_dq(bool flag) {
	cout << '[';
	if (!dq.empty()) {
		if (flag) {
			while (1) {
				cout << dq.front();
				dq.pop_front();
				if (dq.empty()) break;
				cout << ',';
			}
		} else {
			while (1) {
				cout << dq.back();
				dq.pop_back();
				if (dq.empty()) break;
				cout << ',';
			}
		}
	}
	cout << "]\n";
}

void execute_cmd(string cmd) {
	bool flag = true;

	for (int i = 0; i < cmd.length(); ++i) {
		if (cmd[i] == 'R') {
			flag = !flag;
		} else if (cmd[i] == 'D') {
			if (dq.empty()) {
				cout << "error\n";
				return;
			}
			flag ? dq.pop_front() : dq.pop_back();
		}
	}
	
	print_dq(flag);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	while (n--) {
		dq.clear();

		string cmd;
		int m;

		cin >> cmd;
		cin >> m;

		string arr;
		cin >> arr;
		fill_dq(arr);
		execute_cmd(cmd);
	}
}
