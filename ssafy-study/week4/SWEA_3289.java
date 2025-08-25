import java.io.*;
import java.util.*;

public class SWEA_3289 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static StringTokenizer st;
  static int T, n, m;
  static int[] p = new int[1000002];

  static int findp(int x) {
    if (p[x] < 0) return x;
    return p[x] = findp(p[x]); // 경로압축
  }

  static boolean unite(int x, int y) {
    int rx = findp(x);
    int ry = findp(y);
    if (rx == ry) return false; // 이미 같은 그룹
    // union by size (더 '음수'인 쪽이 큰 집합)
    if (p[rx] > p[ry]) { int t = rx; rx = ry; ry = t; }
    p[rx] += p[ry];
    p[ry] = rx;
    return true;
  }

  static void init() {
    Arrays.fill(p, 1, n + 1, -1);
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      st = new StringTokenizer(br.readLine());

      n = Integer.parseInt(st.nextToken());
      m = Integer.parseInt(st.nextToken());

      // 초기화
      init();

      // 실행 & 출력
      sb.append('#').append(tc).append(' ');
      for (int i = 0; i < m; ++i) {
        st = new StringTokenizer(br.readLine());
        int cmd = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        if (cmd == 0) unite(a, b);
        else sb.append((findp(a) == findp(b)) ? '1' : '0');
      }
      sb.append('\n');
    }
    System.out.print(sb);
  }
}
