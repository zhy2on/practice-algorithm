import java.io.*;
import java.util.*;

public class SWEA_3307_dp_ver {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N;
  static int[] arr = new int[1002];

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      N = Integer.parseInt(br.readLine());
      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int i = 0; i < N; ++i) arr[i] = Integer.parseInt(st.nextToken());

      // LIS 구하기
      int[] dp = new int[1002];
      Arrays.fill(dp, 0, N, 1);
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
          if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
        }
      }

      int ans = 0;
      for (int i = 0; i < N; ++i) ans = Math.max(dp[i], ans);
      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }
    System.out.print(sb);
  }
}
