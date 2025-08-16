#include <bits/stdc++.h>
using namespace std;

int N, M;
int card[5000000];

bool binarysearch(int num) {
  int st = 0;
  int en = N - 1;
  while (st < en) {
    int mid = (st + en) / 2;
    if (card[mid] < num) st = mid + 1;
    else en = mid;
  }
  return card[st] == num;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; ++i) cin >> card[i];
  sort(card, card + N);
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int t;
    cin >> t;
    cout << binarysearch(t) << ' ';
  }
}
