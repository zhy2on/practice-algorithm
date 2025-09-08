import java.io.*;
import java.util.*;

/*
 * 공부 시간 한계 - 무게
 * 중요도 합 최대 - 가치
 */

public class BOJ_17845 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static final int I = 0, T = 1;
  static int N, K;
  static int[][] subject = new int[1002][2];

  static int run() {
    int[] dp = new int[N + 1]; // dp[t]: t일 때 최대 중요도 합

    for (int i = 0; i < K; ++i) {
      for (int j = N; j >= subject[i][T]; --j) {
        dp[j] = Math.max(dp[j], dp[j - subject[i][T]] + subject[i][I]);
      }
    }

    int max = 0;
    for (int i = 1; i <= N; ++i) max = Math.max(max, dp[i]);
    return max;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());

    for (int i = 0; i < K; ++i) {
      st = new StringTokenizer(br.readLine());
      subject[i][I] = Integer.parseInt(st.nextToken());
      subject[i][T] = Integer.parseInt(st.nextToken());
    }

    System.out.print(run());
  }
}
