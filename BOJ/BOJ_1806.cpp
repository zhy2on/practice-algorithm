#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int arr[100002];
int N, S;

int main(void) {

    cin >> N >> S;

    for (int i = 0; i < N; ++i) cin >> arr[i];

    int left = 0, sum = 0, len = INT_MAX;
    for (int right = 0; right < N; ++right) {
        sum += arr[right];

        while (sum >= S) {
            len = min(len, right - left + 1);
            sum -= arr[left++];
        }
    }

    if (len == INT_MAX) cout << 0;
    else cout << len;
}
