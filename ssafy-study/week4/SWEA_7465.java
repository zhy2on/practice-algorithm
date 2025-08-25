import java.io.*;
import java.util.*;

public class SWEA_7465 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, M, group;
  static int[] p = new int[102];

  static int findp(int x) {
    if (p[x] < 0) return x;
    return p[x] = findp(p[x]); // 경로압축
  }

  static void unite(int x, int y) {
    int rx = findp(x), ry = findp(y);
    if (rx == ry) return;

    if (p[rx] > p[ry]) { int t = p[rx]; p[rx] = p[ry]; p[ry] = t; } // union-by-size
    p[rx] += p[ry];
    p[ry] = rx;

    --group;
  }

  static void init() {
    Arrays.fill(p, 1, N + 1, -1);
    group = N;
  }


  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());

      init(); // 초기화

      for (int i = 0; i < M; ++i) {
        st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        unite(a, b);
      }

      // 실행
      sb.append('#').append(tc).append(' ').append(group).append('\n');
    }
    System.out.print(sb);
  }
}
