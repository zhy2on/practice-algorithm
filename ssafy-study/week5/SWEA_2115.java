import java.io.*;
import java.util.*;

public class SWEA_2115 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, M, C, maxValue;
  static int[][] board = new int[12][12];
  static int[][] profits = new int[12][12];

  static void dfs(int k, int x, int y, int sum, int value) {
    if (sum > C) return;
    if (k == M) {
      maxValue = Math.max(value, maxValue);
      return;
    }
    dfs(k + 1, x, y, sum, value);
    dfs(k + 1, x, y, sum + board[x][y + k], value + (board[x][y + k] * board[x][y + k]));
  }

  static int getValue(int i, int j) {
    maxValue = 0;
    dfs(0, i, j, 0, 0);
    return maxValue;
  }

  static int run() {
    // 이익 먼저 계산
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= N - M; ++j) {
        profits[i][j] = getValue(i, j);
      }
    }

    // 답 구하기
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= N - M; ++j) {
        // i == k일 때는 안 겹치는 부분부터
        for (int l = j + M; l <= N - M; ++l) {
          ans = Math.max(ans, profits[i][j] + profits[i][l]);
        }

        for (int k = i + 1; k < N; ++k) {
          for (int l = 0; l <= N - M; ++l) {
            ans = Math.max(ans, profits[i][j] + profits[k][l]);
          }
        }
      }
    }
    return ans;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());
      C = Integer.parseInt(st.nextToken());

      for (int i = 0; i < N; ++i) {
        st = new StringTokenizer(br.readLine());
        for (int j = 0; j < N; ++j) board[i][j] = Integer.parseInt(st.nextToken());
      }

      sb.append('#').append(tc).append(' ').append(run()).append('\n');
    }
    System.out.print(sb);
  }
}
