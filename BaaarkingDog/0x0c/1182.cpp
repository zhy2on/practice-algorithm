#include <iostream>

using namespace std;

int N, S;
int arr[20], ans;

void f(int k, int total) {
	if (k == N) return;
	if (total + arr[k] == S) ++ans;
	
	f(k + 1, total);
	f(k + 1, total + arr[k]);
}

int main(void) {
	cin >> N >> S;

	for (int i = 0; i < N; ++i) cin >> arr[i];

	f(0, 0);

	cout << ans;
}
