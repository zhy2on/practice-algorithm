#include <iostream>
using namespace std;

int ssum[1028][1028];
int N, M;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int tmp;
            cin >> tmp;

            ssum[i][j] = ssum[i - 1][j] + ssum[i][j - 1] - ssum[i - 1][j - 1] + tmp;
        }
    }

    for (int i = 0; i < M; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << ssum[x2][y2] - ssum[x1 - 1][y2] - ssum[x2][y1 - 1] + ssum[x1 - 1][y1 - 1] << '\n';
    }
}