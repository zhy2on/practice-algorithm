import java.io.*;
import java.util.*;

public class BOJ_1074 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int N, r, c;

  static void dfs(int x, int y, int n, int cnt) {
    if (n == 1) {
      if (x == r && y == c) {
        System.out.print(cnt);
        System.exit(0);
      }
      return;
    }

    n /= 2;
    // !모든 사분면을 들어가면 시간초과! r, c가 있는 사분면을 선택적으로 타고 타고 들어가야한다.
    if (r < x + n && c < y + n) dfs(x, y, n, cnt);
    else if (r < x + n && c >= y + n) dfs(x, y + n, n, cnt + n * n);
    else if (r >= x + n && c < y + n) dfs(x + n, y, n, cnt + n * n * 2);
    else dfs(x + n, y + n, n, cnt + n * n * 3);
  }
  
  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    r = Integer.parseInt(st.nextToken());
    c = Integer.parseInt(st.nextToken());
    dfs(0, 0, 1 << N, 0);
  }
}
