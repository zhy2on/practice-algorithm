import java.io.*;
import java.util.*;

public class BOJ_9084 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, M;
  static int[] coin = new int[22];

  static int run() {
    // dp[m]: 금액 m을 만드는 총 경우의 수
    // dp[m]은 dp[m] + dp[m - 나] => 원래 있던 값에 나를 쓰는 경우의 수를 더해줘야 하기 때문
    int[] dp = new int[10002];

    dp[0] = 1; // 베이스케이스! 0원을 만드는 경우는 무조건 하나로 가정하고 시작
    for (int i = 0; i < N; ++i) {
      for (int j = coin[i]; j <= M; ++j) {
        dp[j] += dp[j - coin[i]];
      }
    }

    return dp[M];
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      N = Integer.parseInt(br.readLine());
      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int i = 0; i < N; ++i) coin[i] = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(br.readLine());

      sb.append(run()).append('\n');
    }
    System.out.print(sb);
  }
}
