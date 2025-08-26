import java.io.*;
import java.util.*;

public class SWEA_3124 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, V, E;
  static int[] p = new int[100002];
  static int[][] edge = new int[200002][3];

  static int findp(int x) {
    if (p[x] < 0) return x;
    return p[x] = findp(p[x]);
  }

  static boolean unite(int u, int v) {
    u = findp(u); v = findp(v);
    if (u == v) return false;

    if (p[u] > p[v]) { int t = p[u]; p[u] = p[v]; p[v] = t; }
    p[u] += p[v];
    p[v] = u;
    return true;
  }

  static long run() {
    // 간선 정렬
    Arrays.sort(edge, 0, E, (a, b) -> Integer.compare(a[0], b[0]));

    // 크루스칼
    long cost = 0, cnt = 0;
    for (int i = 0; i < E; ++i) {
      if (!unite(edge[i][1], edge[i][2])) continue;
      cost += edge[i][0];
      ++cnt;
      if (cnt == V - 1) break;
    }
    return cost;
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
      StringTokenizer st = new StringTokenizer(br.readLine());
      V = Integer.parseInt(st.nextToken());
      E = Integer.parseInt(st.nextToken());

      for (int i = 0; i < E; ++i) {
        st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        edge[i] = new int[]{c, a, b};
      }

      // 실행 & 출력
      sb.append('#').append(tc).append(' ').append(run()).append('\n');
    }
    System.out.print(sb);
  }
}
