import java.io.*;
import java.util.*;

public class SWEA_7793 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, M;
  static char[][] board = new char[52][52];
  static int[] s, d, e;
  static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  static int run() {
    int[][] distE = new int[N][M];
    int[][] distS = new int[N][M];

    // 악마 먼저
    ArrayDeque<int[]> q = new ArrayDeque<>();
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (board[i][j] == '*') {
          q.offer(new int[]{i, j});
          distE[i][j] = 1;
        }
      }
    }

    while (!q.isEmpty()) {
      int[] cur = q.poll();
      for (int d = 0; d < 4; ++d) {
        int nx = cur[0] + dir[d][0], ny = cur[1] + dir[d][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (board[nx][ny] == 'X' || board[nx][ny] == 'D' || distE[nx][ny] != 0) continue;

        q.offer(new int[]{nx, ny});
        distE[nx][ny] = distE[cur[0]][cur[1]] + 1;
      }
    }

    // 그 다음 수연이
    q.offer(new int[]{s[0], s[1]});
    distS[s[0]][s[1]] = 1;
    
    while (!q.isEmpty()) {
      int[] cur = q.poll();
      for (int d = 0; d < 4; ++d) {
        int nx = cur[0] + dir[d][0], ny = cur[1] + dir[d][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (board[nx][ny] == 'X' || distS[nx][ny] != 0) continue;

        if (board[nx][ny] == 'D') return distS[cur[0]][cur[1]];
        if (distE[nx][ny] != 0 && distS[cur[0]][cur[1]] + 1 >= distE[nx][ny]) continue;

        q.offer(new int[]{nx, ny});
        distS[nx][ny] = distS[cur[0]][cur[1]] + 1;
      }
    }

    return -1;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());

      for (int i = 0; i < N; ++i) {
        board[i] = br.readLine().toCharArray();
        for (int j = 0; j < M; ++j) {
          if (board[i][j] == 'S') s = new int[]{i, j};
          else if (board[i][j] == 'D') d = new int[]{i, j};
          else if (board[i][j] == '*') e = new int[]{i, j};
        }
      }

      // 실행
      int n = run();
      if (n == -1) sb.append('#').append(tc).append(' ').append("GAME OVER").append('\n');
      else sb.append('#').append(tc).append(' ').append(n).append('\n');
    }
    System.out.print(sb);
  }
}
