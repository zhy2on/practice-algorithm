#include <bits/stdc++.h>
using namespace std;

int n, w, L, ans;
int truck[1000];

void run() {
	queue<int> bridge;
	int curl_l = 0, cur = 0;

	// 큐 초기화 필요
	for (int i = 0; i < w; ++i) bridge.push(0);

	while (cur < n || curl_l > 0) {	 // 다리 위에 트럭이 남아있을 수도 있음
		// 매 초마다 다리 한 칸 전진
		curl_l -= bridge.front();
		bridge.pop();

		// 새로운 트럭을 다리에 올릴 수 있는지 확인
		if (cur < n && curl_l + truck[cur] <= L) {
			bridge.push(truck[cur]);
			curl_l += truck[cur++];
		} else {
			bridge.push(0);
		}
		++ans;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> w >> L;
	for (int i = 0; i < n; ++i) cin >> truck[i];
	run();
	cout << ans;
}
