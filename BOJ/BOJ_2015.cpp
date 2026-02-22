#include <iostream>
#include <unordered_map>
using namespace std;

int N, K;
unordered_map<long long, long long> cnt;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    int prefix = 0;
    long long ans = 0;
    cnt[0] = 1;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        prefix += num;

        ans += cnt[prefix - K];
        cnt[prefix]++;
    }
    cout << ans;
}
