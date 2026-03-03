#include <iostream>
#include <cstring>
using namespace std;

int R, C, T, airR1 = -1, airR2;
int board[52][52];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void print() {
    cout << "############\n";
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) cout << board[i][j] << ' ';
        cout << '\n';
    }
    cout << "############\n\n";
}

void air_in() {
    // 위
    for (int x = airR1 - 1; x > 0; --x) {
        board[x][0] = board[x - 1][0];
    }
    for (int y = 0; y < C - 1; ++y) {
        board[0][y] = board[0][y + 1];
    }
    for (int x = 0; x < airR1; ++x) {
        board[x][C - 1] = board[x + 1][C - 1];
    }
    for (int y = C - 1; y > 0; --y) {
        board[airR1][y] = board[airR1][y - 1];
    }

    // 아래
    for (int x = airR2 + 1; x < R - 1; ++x) {
        board[x][0] = board[x + 1][0];
    }
    for (int y = 0; y < C - 1; ++y) {
        board[R - 1][y] = board[R - 1][y + 1];
    }
    for (int x = R - 1; x > airR2; --x) {
        board[x][C - 1] = board[x - 1][C - 1];
    }
    for (int y = C - 1; y > 0; --y) {
        board[airR2][y] = board[airR2][y - 1];
    }

    board[airR1][0] = -1;
    board[airR1][1] = 0;
    board[airR2][0] = -1;
    board[airR2][1] = 0;
}

void spread() {
    int tmp[52][52] = {};

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (board[i][j] == -1) {
                tmp[i][j] = -1;
                continue;
            }

            tmp[i][j] += board[i][j];
            if (board[i][j] <= 0) continue;

            for (int d = 0; d < 4; ++d) {
                int nx = i + dx[d], ny = j + dy[d];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (board[nx][ny] == -1) continue;
                
                tmp[nx][ny] += board[i][j] / 5;
                tmp[i][j] -= board[i][j] / 5;
            }
        }
    }

    for (int i = 0; i < R; ++i) memcpy(board[i], tmp[i], sizeof(board[i]));
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C >> T;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> board[i][j];
            if (board[i][j] < 0) {
                if (airR1 == -1) airR1 = i;
                else airR2 = i;
            }
        }
    }

    while (T--) {
        spread();
        air_in();
    }

    int ans = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (board[i][j] > 0) ans += board[i][j];
        }
    }

    cout << ans;

}