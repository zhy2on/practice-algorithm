#include <iostream>
#include <string>
using namespace std;

int dp[1002][1002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a;
    string b;
    cin >> a;
    cin >> b;

    for (int i = 1; i <= a.size(); ++i) {
        for (int j = 1; j <= b.size(); ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[a.size()][b.size()];
}
