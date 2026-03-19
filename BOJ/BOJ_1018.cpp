#include <iostream>
#include <algorithm>
using namespace std;

bool board[52][52];
int ans = 999999;
int N, M;

void updateAns(int sx, int sy) {
    int cnt1 = 0, cnt2 = 0;
    bool flag1 = true, flag2 = false;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            int x = sx + i, y = sy + j;
            if (x >= N || y >= M) return;

            if (board[x][y] != flag1) ++cnt1;
            if (board[x][y] != flag2) ++cnt2;

            if (cnt1 >= ans && cnt2 >= ans) return;

            flag1 = !flag1;
            flag2 = !flag2;
        }
        flag1 = !flag1;
        flag2 = !flag2;
    }
    ans = min(cnt1, cnt2);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            board[i][j] = c == 'W' ? true : false;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) updateAns(i, j);
    }

    cout << ans;
}
