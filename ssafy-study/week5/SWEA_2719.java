import java.io.*;
import java.util.*;

public class SWEA_2719 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, ans;
  static int[][] board = new int[4][4];
  static int[][] dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  static boolean[] chk = new boolean[10000000];

  static void dfs(int k, int x, int y, int num) {
    if (k == 6) {
      if (!chk[num]) {
        ++ans;
        chk[num] = true;
      }
      return;
    }
    for (int d = 0; d < 4; ++d) {
      int nx = x + dir[d][0], ny = y + dir[d][1];
      if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
      dfs(k + 1, nx, ny, num * 10 + board[nx][ny]);
    }
  }

  static void run() {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        dfs(0, i, j, board[i][j]);
      }
    }
  }

  static void init() {
    Arrays.fill(chk, false);
    ans = 0;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      init();
      for (int i = 0; i < 4; ++i) { 
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int j = 0; j < 4; ++j) board[i][j] = Integer.parseInt(st.nextToken());
      }
      run();
      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }
    System.out.print(sb);
  }
}
