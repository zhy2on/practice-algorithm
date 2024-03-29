#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool visited[10];

void f(int k) {
	if (k == m) {
		for (int i = 0; i < m; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			arr[k] = i;
			visited[i] = 1;
			f(k + 1);
			visited[i] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	f(0);
}
