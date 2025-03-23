#include <iostream>
using namespace std;

int n;
int arr[1001];
int tmp[1001];

void bubble_sort() {
	for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n - 1 - i; ++j)
      if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
  }
}

void merge(int st, int en) {
  int mid = (st + en) / 2;
  int lidx = st, ridx = mid;
  for (int i = st; i < en; ++i) {
    if (ridx == en) tmp[i] = arr[lidx++];
    else if (lidx == mid) tmp[i] = arr[ridx++];
    else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
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
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
  merge_sort(0, n);
  for (int i = 0; i < n; ++i) cout << arr[i] << '\n';
}
