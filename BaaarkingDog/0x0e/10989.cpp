#include <iostream>
using namespace std;

int N, num;
int arr[10001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		++arr[num];
	}
	for (int i = 0; i < N; ++i) {
		while (arr[i]--) {
			cout << i << '\n';
		}
	}
}
