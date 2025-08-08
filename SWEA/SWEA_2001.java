import java.io.*;
import java.util.*;

public class SWEA_2001 {

  static int N, M, ans;
  static int[][] board = new int[16][16];
  static int[][] prefixSum = new int[16][16];
  static StringBuilder sb = new StringBuilder();
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

  static void setPrefixSum() {
    // pr[i,j] = arr[i, j] + pr[i-1, j] + pr[i, j-1] - pr[i-1, j-1]
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        prefixSum[i][j] = board[i][j]
                          + prefixSum[i - 1][j]
                          + prefixSum[i][j - 1]
                          - prefixSum[i - 1][j - 1];
      }
    }
  }

  static void killFly() {
    setPrefixSum();

    for (int i = M; i <= N; ++i) {
      for (int j = M; j <= N; ++j) {
        int sum = prefixSum[i][j]
                  - prefixSum[i - M][j]
                  - prefixSum[i][j - M]
                  + prefixSum[i - M][j - M];
        ans = Math.max(ans, sum);
      }
    }
  }

  static void init() {
    ans = 0;
  }

  public static void main(String[] args) throws IOException {
    int T = Integer.parseInt(br.readLine());

    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());

      for (int i = 1; i <= N; ++i) {
        st = new StringTokenizer(br.readLine());
        for (int j = 1; j <= N; ++j) {
          board[i][j] = Integer.parseInt(st.nextToken());
        }
      }

      // 초기화
      init();

      // 실행
      killFly();

      // 출력
      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }

    System.out.print(sb);
  }
}
