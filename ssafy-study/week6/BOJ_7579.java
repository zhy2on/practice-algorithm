import java.io.*;
import java.util.*;

/*
 * 비용을 최소화해야 한다
 * M 바이트 이상은 꺼야됨
 * 비용은 최소가 되게 해야함
 * gma.. dp[c]: c일 때 최대 메모리
 * C는 total cost로 하면 됨
 */

public class BOJ_7579 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static final int MEM = 0, COST = 1;
  static int N, M;
  static int[][] app = new int[102][2];

  static int run() {
    // C 구하기
    int C = 0;
    for (int i = 0; i < N; ++i) C += app[i][COST];

    // dp 구하기 dp[c]: c일 때 최대 메모리.
    int[] dp = new int[10002];
    for (int i = 0; i < N; ++i) {
      for (int j = C; j >= app[i][COST]; --j) {
        dp[j] = Math.max(dp[j], dp[j - app[i][COST]] + app[i][MEM]);
      }
    }

    // M 넘어갈 때 바로 리턴
    for (int c = 0; c <= 10002; ++c) {
      if (dp[c] >= M) return c;
    }
    return -1;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; ++i) app[i][MEM] = Integer.parseInt(st.nextToken());

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; ++i) app[i][COST] = Integer.parseInt(st.nextToken());

    System.out.print(run());
  }
}
