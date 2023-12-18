#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N, M, ans = 9999999;
pair<int, int> selected[13];
vector<pair<int, int> > chicken, house;

void dfs(int t, int idx) {
	if (t == M) {
		int dd = 0;
		for (int i = 0; i < house.size(); ++i) {
			int d = 9999999;
			for (int j = 0; j < M; ++j) {
				d = min(d, abs(house[i].X - selected[j].X) +
							   abs(house[i].Y - selected[j].Y));
			}
			dd += d;
		}
		ans = min(ans, dd);
		return;
	}
	for (int i = idx; i < chicken.size(); ++i) {
		selected[t] = chicken[i];
		dfs(t + 1, i + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int k;
			cin >> k;
			if (k == 1)
				house.push_back({i, j});
			else if (k == 2)
				chicken.push_back({i, j});
		}
	}

	dfs(0, 0);
	cout << ans;
}
