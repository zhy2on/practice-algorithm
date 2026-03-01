#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int H, W, ans;
int block[502];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> H >> W;
    for (int i = 0; i < W; ++i) cin >> block[i];
    
    for (int i = 1; i < W - 1; ++i) {

        int left = block[i], right = block[i];
        for (int j = 0; j < i; ++j) {
            left = max(left, block[j]);
        }

        for (int j = i + 1; j < W; ++j) {
            right = max(right, block[j]);
        }
        
        ans += min(left, right) - block[i];
    }
    cout << ans;
}
