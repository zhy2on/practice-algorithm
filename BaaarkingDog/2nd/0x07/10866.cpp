#include <bits/stdc++.h>
using namespace std;

int dq[200001], head = 100001, tail = 100000;

int size() { return tail - head + 1; }

bool empty() { return head > tail; }

void push_front(int x) { dq[--head] = x; }

void push_back(int x) { dq[++tail] = x; }

int pop_front() {
	if (empty()) return -1;
	return dq[head++];
}

int pop_back() {
	if (empty()) return -1;
	return dq[tail--];
}

int front() {
	if (empty()) return -1;
	return dq[head];
}

int back() {
	if (empty()) return -1;
	return dq[tail];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push_front") {
			int x;
			cin >> x;
			push_front(x);
		} else if (cmd == "push_back") {
			int x;
			cin >> x;
			push_back(x);
		} else if (cmd == "pop_front") {
			cout << pop_front() << '\n';
		} else if (cmd == "pop_back") {
			cout << pop_back() << '\n';
		} else if (cmd == "size") {
			cout << size() << '\n';
		} else if (cmd == "empty") {
			cout << empty() << '\n';
		} else if (cmd == "front") {
			cout << front() << '\n';
		} else if (cmd == "back") {
			cout << back() << '\n';
		}
	}
}
