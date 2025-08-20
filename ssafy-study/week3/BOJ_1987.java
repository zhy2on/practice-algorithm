import java.io.*;
import java.util.*;

public class BOJ_1987 {
  
  static BufferedReader br;
  static int R, C, ans;
  static char[][] board = new char[22][22];
  static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  static void dfs(int x, int y, int cnt, int mask) {
    ans = Math.max(ans, cnt); // 정답 업데이트
    for (int d = 0; d < 4; ++d) { // 방향별로
      int nx = x + dir[d][0], ny = y + dir[d][1];
      if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

      int bit = 1 << (board[nx][ny] - 'A'); // nx, ny번 방문 비트
      if ((mask & bit) != 0) continue; // 이미 켜져 있었으면 continue

      dfs(nx, ny, cnt + 1, mask | bit); // 새로운 알파벳 방문 비트 켜서 넘기기
    }
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    R = Integer.parseInt(st.nextToken());
    C = Integer.parseInt(st.nextToken());

    for (int i = 0; i < R; ++i) board[i] = br.readLine().toCharArray();

    dfs(0, 0, 1, 1 << (board[0][0] - 'A')); // 0, 0번 방문 비트 켜기
    System.out.print(ans);
  }
}
