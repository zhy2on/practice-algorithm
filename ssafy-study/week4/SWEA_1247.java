import java.io.*;
import java.util.*;

public class SWEA_1247 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, ans;
  static int[][] loca = new int[15][2];
  static boolean[] vis = new boolean[15];

  static void dfs(int k, int x, int y, int dist) {
    if (dist > ans) return;

    if (k == N) {
      int d = Math.abs(loca[1][0] - x) + Math.abs(loca[1][1] - y); // 집과 거리
      ans = Math.min(ans, dist + d);
      return;
    }

    for (int i = 2; i < N + 2; ++i) {
      if (vis[i]) continue;
      vis[i] = true;
      int d = Math.abs(loca[i][0] - x) + Math.abs(loca[i][1] - y);
      dfs(k + 1, loca[i][0], loca[i][1], dist + d);
      vis[i] = false;
    }
  }

  static void init() {
    ans = Integer.MAX_VALUE;
    Arrays.fill(vis, false);
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 초기화
      init();

      // 입력
      N = Integer.parseInt(br.readLine());
      StringTokenizer st = new StringTokenizer(br.readLine());

      for (int i = 0; i < N + 2; ++i) { // 회사, 집, N개 좌표
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        loca[i] = new int[]{x, y};
      }

      // 실행
      dfs(0, loca[0][0], loca[0][1], 0);

      // 출력
      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }
    System.out.print(sb);
  }
}
