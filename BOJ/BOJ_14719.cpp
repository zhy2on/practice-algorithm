#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int H, W, ans;
int block[502];
int L[502], R[502];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> H >> W;
    for (int i = 0; i < W; ++i) cin >> block[i];
    
    L[0] = block[0];
    for (int i = 1; i < W - 1; ++i) L[i] = max(L[i - 1], block[i]);

    R[W - 1] = block[W - 1];
    for (int i = W - 2; i > 0; --i) R[i] = max(R[i + 1], block[i]);

    for (int i = 1; i < W - 1; ++i) ans += min(L[i], R[i]) - block[i];
    cout << ans;
}
