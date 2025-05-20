#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time = bridge_length, cur_weight = 0, idx = 0;
	queue<int> bridge;

	while (idx < truck_weights.size()) {
		++time;

		if (bridge.size() == bridge_length) {
			cur_weight -= bridge.front();
			bridge.pop();
		}
		if (cur_weight + truck_weights[idx] <= weight) {
			cur_weight += truck_weights[idx];
			bridge.push(truck_weights[idx++]);
		} else {
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
