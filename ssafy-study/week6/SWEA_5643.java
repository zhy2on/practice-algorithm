import java.io.*;
import java.util.*;

public class SWEA_5643 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, M;

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      N = Integer.parseInt(br.readLine());
      M = Integer.parseInt(br.readLine());
      boolean[][] g = new boolean[502][502];
      for (int i = 0; i < M; ++i) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        g[a][b] = true;
      }

      // 플로이드 워셜
      for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
          if (!g[i][k] && i != k) continue;
          for (int j = 1; j <= N; ++j) {
            if (g[i][k] && g[k][j]) g[i][j] = true;
          }
        }
      }

      // 내 키 알 수 있나
      int ans = 0;
      for (int i = 1; i <= N; ++i) {
        int known = 0;
        for (int j = 1; j <= N; ++j) {
          if (i == j) continue;
          if (g[i][j] || g[j][i]) ++known;
        }
        if (known == N - 1) ++ans;
      }

      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }
    System.out.print(sb);
  }
}
