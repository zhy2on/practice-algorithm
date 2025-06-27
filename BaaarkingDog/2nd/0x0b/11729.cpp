#include <bits/stdc++.h>
using namespace std;

void print_hanoi(int n, int from, int to) {
	if (n == 1) {
		cout << from << ' ' << to << '\n';
		return;
	}

	// f(n-1) + 1 + f(n-1): n-1개를 빈 곳에 옮기고 + n번째를 to에 옮기고 + n-1을
	print_hanoi(n - 1, from, 6 - from - to);
	cout << from << ' ' << to << '\n';
	print_hanoi(n - 1, 6 - from - to, to);
}

int hanoi(int n) {
	if (n == 1) return 1;
	return 2 * hanoi(n - 1) + 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cout << hanoi(n) << '\n';
	print_hanoi(n, 1, 3);
}
