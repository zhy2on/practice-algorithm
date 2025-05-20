#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time = 0, cur_weight = 0, idx = 0;
	queue<int> bridge;

	for (int i = 0; i < bridge_length; ++i) bridge.push(0);

	while (!bridge.empty()) {
		++time;

		// 트럭이 이동. 맨 앞에 있는 트럭이 다리를 지나감
		cur_weight -= bridge.front();
		bridge.pop();

		// 들어올 트럭이 있다면
		if (idx < truck_weights.size()) {
			// 트럭이 들어올 수 있으면 들여보내기
			if (cur_weight + truck_weights[idx] <= weight) {
				cur_weight += truck_weights[idx];
				bridge.push(truck_weights[idx++]);
			} else	// 들어올 수 없으면 빈 공간 추가
				bridge.push(0);
		}
	}
	return time;
}

int main(void) {
	cout << solution(2, 10, {7, 4, 5, 6}) << '\n';
	cout << solution(100, 100, {10}) << '\n';
	cout << solution(100, 100, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10})
		 << '\n';
}
