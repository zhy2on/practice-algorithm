#include <bits/stdc++.h>
using namespace std;

int N, arr[4][10][10];

void run(int t) {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> arr[0][i][j];
	}

	for (int r = 1; r < 4; ++r) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				arr[r][i][j] = arr[r - 1][N - 1 - j][i];
			}
		}
	}

	cout << '#' << t << '\n';
	for (int i = 0; i < N; ++i) {
		for (int r = 1; r < 4; ++r) {
			for (int j = 0; j < N; ++j) cout << arr[r][i][j];
			cout << ' ';
		}
		cout << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) run(t);
}
