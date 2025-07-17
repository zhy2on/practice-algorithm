#include <bits/stdc++.h>
using namespace std;

int T, n, l;

void run(int t) {
  int dp[10001] = {};
  cin >> n >> l;

  for (int i = 0; i < n; ++i) {
    int score, calo;
    cin >> score >> calo;

    // 뒤에서부터 for문을 도는 이유: 한 물건을 딱 한 번만 넣기 위해.
    // 원래의 dp[j - calo]는 내가 포함 되지 않았을 때의 최대 가치여야 한다.
    // 그런데 앞에서부터 for문을 돌아버리면
    // 내가 포함됐을 때의 최대 가치로 dp[j - calo]가 업데이트돼버릴 수 있다.
    // 이러면 이미 내가 포함돼있는 상태의 dp 값에 또 값을 더해버릴 수가 있다.
    for (int j = l; j >= calo; --j) {
      // dp[j]: 가방이 j 무게일 때 최대 가치. dp[j]를 업데이트 해나가야 한다.
      // 원래 있던 dp[j]는 내가 포함 안 됐을 때 j 무게의 최대 가치
      // 내가 포함 돼서 j 무게가 될 때의 최대 가치는 dp[j - calo] + score
      // 둘을 비교해서 큰 값으로 업데이트 해줘야 한다.
      dp[j] = max(dp[j], dp[j - calo] + score);
    }
  }

  int ans = *max_element(dp, dp + l + 1);
  cout << '#' << t << ' ' << ans << '\n';
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 1; t <= T; ++t) run(t);
}

/*
0/1 knapsack problem
*/
