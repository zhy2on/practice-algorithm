#include <bits/stdc++.h>
using namespace std;

int n, w, L, ans;
int truck[1000];

void run() {
	queue<int> bridge;
	int curl_l = 0, cur = 0;

	for (int i = 0; i < w; ++i) bridge.push(0);

	while (cur < n) {
		curl_l -= bridge.front();
		bridge.pop();

		if (curl_l + truck[cur] <= L) {
			bridge.push(truck[cur]);
			curl_l += truck[cur++];
		} else {
			bridge.push(0);
		}
		++ans;
	}
	ans += w;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> w >> L;
	for (int i = 0; i < n; ++i) cin >> truck[i];
	run();
	cout << ans;
}
