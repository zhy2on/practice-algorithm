#include <bits/stdc++.h>
using namespace std;

int arr[100][100];

int stop_count(int col) {
	int cnt = 0;
	bool N_flag = false;
	for (int i = 0; i < 100; ++i) {
		if (!N_flag && arr[i][col] == 1) {
			N_flag = true;
			continue;
		}
		if (N_flag && arr[i][col] == 2) {
			++cnt;
			N_flag = false;
		}
	}
	return cnt;
}

int main(void) {
	for (int t = 0; t < 10; ++t) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) cin >> arr[i][j];
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cnt += stop_count(i);
		}
		cout << '#' << t + 1 << ' ' << cnt << '\n';
	}
}
