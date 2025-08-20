import java.io.*;
import java.util.*;

public class BOJ_1987 {
  
  static BufferedReader br;
  static int R, C, ans;
  static char[][] board = new char[22][22];
  static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  static boolean[] alpha = new boolean[26];

  static void dfs(int x, int y, int cnt) {
    ans = Math.max(ans, cnt); // 정답 업데이트
    for (int d = 0; d < 4; ++d) { // 방향별로
      int nx = x + dir[d][0], ny = y + dir[d][1];
      if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
      if (alpha[board[nx][ny] - 'A']) continue;

      // 갈 수 있다면
      alpha[board[nx][ny] - 'A'] = true; // 값 업데이트하고
      dfs(nx, ny, cnt + 1); // 들어가고
      alpha[board[nx][ny] - 'A'] = false; // 나와서 다시 복구 
    }
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    R = Integer.parseInt(st.nextToken());
    C = Integer.parseInt(st.nextToken());

    for (int i = 0; i < R; ++i) board[i] = br.readLine().toCharArray();

    alpha[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    System.out.print(ans);
  }
}
