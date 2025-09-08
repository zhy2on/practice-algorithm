import java.io.*;
import java.util.*;

public class BOJ_12865 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static final int W = 0, V = 1;
  static int N, K;
  static int[][] bag = new int[102][2];

  static int run() {
    int[] dp = new int[K + 1];

    for (int i = 0; i < N; ++i) {
      for (int j = K; j >= bag[i][W]; --j) {
        dp[j] = Math.max(dp[j], dp[j - bag[i][W]] + bag[i][V]);
      }
    }

    int max = 0;
    for (int i = 1; i <= K; ++i) max = Math.max(max, dp[i]);
    return max;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());

    for (int i = 0; i < N; ++i) {
      st = new StringTokenizer(br.readLine());
      bag[i][W] = Integer.parseInt(st.nextToken());
      bag[i][V] = Integer.parseInt(st.nextToken());
    }

    System.out.print(run());
  }
}
