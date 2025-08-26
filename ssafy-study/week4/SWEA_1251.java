import java.io.*;
import java.util.*;

public class SWEA_1251 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N;
  static double E;
  static int[][] island = new int[1005][2];
  static long[][] edge = new long[1005 * 1005][]; // cost, a, b
  static int[] p = new int[1005];

  static int findp(int x) {
    if (p[x] < 0) return x;
    return p[x] = findp(p[x]);
  }

  static boolean is_diff_group(int u, int v) {
    u = findp(u); v = findp(v);
    if (u == v) return false;

    if (p[u] > p[v]) { int t = p[u]; p[u] = p[v]; p[v] = t; }
    p[u] += p[v];
    p[v] = u;
    return true;
  }

  static long run() {
    // 먼저 간선 비용 구하기
    int idx = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        long dx = island[i][0] - island[j][0];
        long dy = island[i][1] - island[j][1];
        edge[idx++] = new long[] {dx * dx + dy * dy, i, j};
      }
    }

    // 간선 정렬
    Arrays.sort(edge, 0, idx, (a, b) -> Long.compare(a[0], b[0]));

    // 크루스칼 알고리즘
    long cost = 0, cnt = 0; 
    for (int i = 0; i < idx; ++i) {
      if (!is_diff_group((int) edge[i][1], (int) edge[i][2])) continue;
      cost += edge[i][0];
      ++cnt;
      if (cnt == N - 1) break;
    }
    return Math.round(cost * E);
  }

  static void init() {
    Arrays.fill(p, -1);
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());

    for (int tc = 1; tc <= T; ++tc) {
      // 초기화
      init();

      // 입력
      N = Integer.parseInt(br.readLine());
      // x좌표
      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int i = 0; i < N; ++i) island[i][0] = Integer.parseInt(st.nextToken());

      // y좌표
      st = new StringTokenizer(br.readLine());
      for (int i = 0; i < N; ++i) island[i][1] = Integer.parseInt(st.nextToken());

      // 세율
      E = Double.parseDouble(br.readLine());

      // 실행 & 출력
      sb.append('#').append(tc).append(' ').append(run()).append('\n');
    }
    System.out.print(sb);
  }
}
