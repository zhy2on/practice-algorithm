#include <iostream>
using namespace std;

int N, num;
int arr[2000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		++arr[num + 1000000];
	}

	for (int i = 0; i < 2000001; ++i) {
		while (arr[i]--) cout << i - 1000000 << '\n';
	}
}
