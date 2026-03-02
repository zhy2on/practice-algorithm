#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[100002];

int binarysearch(int target) {
    int st = 0;
    int en = N - 1;

    while (st <= en) {
        int mid = (st + en) / 2;
        if (A[mid] < target) st = mid + 1;
        else if (A[mid] > target) en = mid - 1;
        else return 1;
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A, A + N);

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int t;
        cin >> t;
        cout << binarysearch(t) << '\n';
    }
}