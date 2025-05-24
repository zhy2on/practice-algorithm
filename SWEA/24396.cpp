#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t_c;
	cin >> t_c;

	for (int t = 0; t < t_c; ++t) {
		int b, w, x, y, z;
		cin >> b >> w >> x >> y >> z;
		int case_1, case_2;
		case_1 = (b * x) + (w * y);

		// 최대 검흰 + 나머지 검검 or 흰흰
		if (b > w) {
			case_2 = (w * z * 2) + ((b - w) * x);
		} else {
			case_2 = (b * z * 2) + ((w - b) * y);
		}

		cout << max(case_1, case_2) << '\n';
	}
}

/*
모든 상자가 한 개의 공
검 검 X
흰 흰 Y
검 흰 Z

1) 검검 흰흰 하거나 -> b * x + w * y
2) 최대 검흰 + 나머지 검검 or 흰흰
*/
