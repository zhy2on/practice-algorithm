#include <bits/stdc++.h>
using namespace std;

int N, K;
int line[1000000];

bool enough(int x) {
  int cnt = 0;
  for (int i = 0; i < K; ++i) cnt += line[i] / x;
  return cnt >= N;
}

int binarysearch() {
  long st = 1; // st + en 계산이 int 범위를 초과할 수 있기 때문에 long 필요
  long en = INT_MAX;
  while (st < en) {
    long mid = (st + en + 1) / 2; // st, en이 1차이가 날 때 mid가 st가 돼버려서 st < en을 항상 만족해 무한루프 도는 것 방지
    if (enough(mid)) st = mid; // 충분하다면 더 큰 값이 있을 수도 있음. 하지만 나도 정답 후보이기 때문에 st = mid + 1이 아니라 st = mid;를 해줘야 함
    else en = mid - 1; // 충분하지 않다면 난 정답 후보도 아님. en = mid - 1;
  }
  return st;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> K >> N;
  for (int i = 0; i < K; ++i) cin >> line[i];
  cout << binarysearch();
}
