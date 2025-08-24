import java.util.*;
import java.io.*;

public class SWEA_1227 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static final int N = 100;
  static final int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};
  static char[][] board = new char[N][N];

  static int bfs(int sx, int sy) {
    ArrayDeque<int[]> q = new ArrayDeque<>();
    q.add(new int[]{sx, sy});
    board[sx][sy] = '1';

    while (!q.isEmpty()) {
      int[] cur = q.poll();
      int x = cur[0], y = cur[1];

      for (int i = 0; i < 4; ++i) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // OOB check
        if (board[nx][ny] == '1') continue; // visitable check

        if (board[nx][ny] == '3') return 1;
        q.add(new int[]{nx, ny});
        board[nx][ny] = '1';
      }
    }
    return 0;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    for (int tc = 1; tc <= 10; tc++) {
      br.readLine(); // 케이스 번호 건너뛰기

      int sx = -1, sy = -1;
      for (int i = 0; i < N; i++) {
          board[i] = br.readLine().toCharArray();
          for (int j = 0; j < N; j++) {
            if (board[i][j] == '2') { // 시작점
              sx = i; sy = j;
            }
          }
      }
      sb.append('#').append(tc).append(' ').append(bfs(sx, sy)).append('\n');
    }
    System.out.print(sb);
  }
}
