#include <iostream>

using namespace std;

int N;
long long dp[102][102];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    dp[0][0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            long long n;
            cin >> n;
            if (n == 0) continue;

            if (i + n < N) dp[i + n][j] += dp[i][j];
            if (j + n < N) dp[i][j + n] += dp[i][j];
        }
    }
    
    cout << dp[N - 1][N - 1];
}
