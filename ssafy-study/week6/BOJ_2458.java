import java.io.*;
import java.util.*;

public class BOJ_2458 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static final int INF = 0x3f3f3f3f;
  static int N, M;
  static boolean[][] g = new boolean[502][502];

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    for (int i = 0; i < M; ++i) {
      st = new StringTokenizer(br.readLine());
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());
      g[a][b] = true;
    }

    // 플로이드 워셜 O(N^3)
    for (int k = 1; k <= N; ++k) { // k: 중간 노드가 될 노드 번호
      for (int i = 1; i <= N; ++i) {
        if (!g[i][k] && i != k) continue;
        for (int j = 1; j <= N; ++j) {
          if (g[i][k] && g[k][j]) g[i][j] = true;
        }
      }
    }

    // 내 키를 알 수 있나
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
      int known = 0;
      for (int j = 1; j <= N; ++j) {
        if (i == j) continue;
        if (g[i][j] || g[j][i]) ++known;
      }
      if (known == N - 1) ++ans;
    }
    System.out.print(ans);
  }
}
