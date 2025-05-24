#include <bits/stdc++.h>
using namespace std;

int score[101];

int main(void) {
	for (int t = 1; t <= 10; ++t) {
		int tmp;
		cin >> tmp;

		fill(score, score + 101, 0);
		for (int j = 0; j < 1000; ++j) {
			int s;
			cin >> s;
			score[100 - s]++;
		}

		cout << '#' << t << ' '
			 << abs(100 - (max_element(score, score + 101) - score)) << '\n';
	}
}
