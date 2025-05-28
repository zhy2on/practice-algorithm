#include <bits/stdc++.h>
using namespace std;

int q[2000001], head = 1, tail;

int size() { return tail - head + 1; }

bool empty() { return head > tail; }

int front() {
	if (empty()) return -1;
	return q[head];
}

int back() {
	if (empty()) return -1;
	return q[tail];
}

void push(int x) { q[++tail] = x; }

int pop() {
	if (empty()) return -1;
	return q[head++];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int x;
			cin >> x;
			push(x);
		} else if (cmd == "pop") {
			cout << pop() << '\n';
		} else if (cmd == "front") {
			cout << front() << '\n';
		} else if (cmd == "back") {
			cout << back() << '\n';
		} else if (cmd == "size") {
			cout << size() << '\n';
		} else if (cmd == "empty") {
			cout << empty() << '\n';
		}
	}
}
