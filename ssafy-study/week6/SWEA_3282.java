import java.io.*;
import java.util.*;

public class SWEA_3282 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static final int V = 0, C = 1;
  static int T, N, K;
  static int[][] bag = new int[102][2];

  static int run() {
    int[] dp = new int[K + 1]; // dp[v]: 부피합이 v일 때 최대가치
    // 부피합 최대가치 [날 담지 않았을 때 최대 vs 날 담았을 때 최대]
    for (int i = 0; i < N; ++i) {
      for (int j = K; j >= bag[i][V]; --j) {
        dp[j] = Math.max(dp[j], dp[j - bag[i][V]] + bag[i][C]);
      }
    }
    int max = 0;
    for (int i = 1; i <= K; ++i) max = Math.max(max, dp[i]);
    return max;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      K = Integer.parseInt(st.nextToken());

      for (int i = 0; i < N; ++i) {
        st = new StringTokenizer(br.readLine());
        bag[i][V] = Integer.parseInt(st.nextToken());
        bag[i][C] = Integer.parseInt(st.nextToken());
      }

      sb.append('#').append(tc).append(' ').append(run()).append('\n');
    }
    System.out.print(sb);
  }
}
