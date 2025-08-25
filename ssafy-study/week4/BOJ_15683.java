import java.io.*;
import java.util.*;

public class BOJ_15683 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int N, M, cctvCnt, watched, empty;
  static int[][] cctv = new int[8][3];
  static int[][] board = new int[8][8];
  static int[][] simul = new int[8][8];
  static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  static int[] cctvDir = new int[8];

  static int watch(int x, int y, int d) {
    int cnt = 0;
    while (true) {
      x += dir[d][0];
      y += dir[d][1];
      if (x < 0 || x >= N || y < 0 || y >= M) break;
      if (simul[x][y] == 6) break;
      if (simul[x][y] == 0) {
        simul[x][y] = -1;
        ++cnt;
      }
    }
    return cnt;
  }

  static void run() {
    int cnt = 0;
    for (int k = 0; k < cctvCnt; ++k) {
      int d = cctvDir[k], x = cctv[k][0], y = cctv[k][1], n = cctv[k][2];
      if (n == 1) {
        cnt += watch(x, y, d);
      } else if (n == 2) {
        cnt += watch(x, y, d);
        cnt += watch(x, y, d + 2);
      } else if (n == 3) {
        cnt += watch(x, y, d);
        cnt += watch(x, y, (d + 1) % 4);
      } else if (n == 4) {
        cnt += watch(x, y, d);
        cnt += watch(x, y, (d + 1) % 4);
        cnt += watch(x, y, (d + 2) % 4);
      } else if (n == 5) {
        cnt += watch(x, y, d);
        cnt += watch(x, y, d + 1);
        cnt += watch(x, y, d + 2);
        cnt += watch(x, y, d + 3);
      }
    }
    watched = Math.max(cnt, watched);
  }

  static void dfs(int k) {
    if (k == cctvCnt) {
      for (int i = 0; i < N; ++i) System.arraycopy(board[i], 0, simul[i], 0, M);
      run();
      return;
    }
    int n = cctv[k][2];
    if (n == 2) {
      for (int d = 0; d < 2; ++d) {
        cctvDir[k] = d;
        dfs(k + 1);
      }
    } else if (n == 5) {
      cctvDir[k] = 0;
      dfs(k + 1);
    } else {
      for (int d = 0; d < 4; ++d) {
        cctvDir[k] = d;
        dfs(k + 1);
      }
    }
  }


  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    for (int i = 0; i < N; ++i) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < M; ++j) {
        board[i][j] = Integer.parseInt(st.nextToken());
        if (board[i][j] > 0 && board[i][j] < 6) cctv[cctvCnt++] = new int[] {i, j, board[i][j]};
        else if (board[i][j] == 0) ++empty;
      }
    }

    dfs(0);
    System.out.print(empty - watched);
  }
}
