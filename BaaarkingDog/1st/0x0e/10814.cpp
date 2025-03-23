#include <iostream>
#include <vector>
using namespace std;

#define X first
#define Y second

int N;
pair<int, string> arr[100001], tmp[100001];

void merge(int st, int en) {
	int mid = (st + en) / 2;
	int lidx = st, ridx = mid;
	for (int i = st; i < en; ++i) {
		if (ridx == en) tmp[i] = arr[lidx++];
		else if (lidx == mid) tmp[i] = arr[ridx++];
		else if (arr[lidx].X <= arr[ridx].X) tmp[i] = arr[lidx++];
		else tmp[i] = arr[ridx++];
	}
	for (int i = st; i < en; ++i) arr[i] = tmp[i];
}

void merge_sort(int st, int en) {
	int mid = (st + en) / 2;
	if (en == st + 1) return;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i].X >> arr[i].Y;
	merge_sort(0, N);
	for (int i = 0; i < N; ++i) cout << arr[i].X << ' ' << arr[i].Y << '\n';
}
