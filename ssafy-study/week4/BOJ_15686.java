import java.io.*;
import java.util.*;

public class BOJ_15686 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int N, M, chickCnt, houseCnt, ans = Integer.MAX_VALUE;
  static int[][] board = new int[52][52];
  static int[][] chickens = new int[15][2];
  static int[][] selected = new int[15][2];
  static int[][] houses = new int[102][2];

  static void updateAns() {
    int dist = 0;
    for (int i = 0; i < houseCnt; ++i) { // 각 집마다 치킨거리 구하기
      int d = Integer.MAX_VALUE;
      for (int j = 0; j < M; ++j) {
        int tmp = Math.abs(houses[i][0] - selected[j][0]) + Math.abs(houses[i][1] - selected[j][1]);
        d = Math.min(tmp, d);
      }
      dist += d;
    }
    ans = Math.min(ans, dist);
  }

  static void dfs(int k, int st) {
    if (k == M) {
      updateAns();
      return;
    }

    for (int i = st; i < chickCnt; ++i) {
      selected[k] = new int[]{chickens[i][0], chickens[i][1]};
      dfs(k + 1, i + 1);
    }
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    for (int i = 0; i < N; ++i) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < N; ++j) {
        board[i][j] = Integer.parseInt(st.nextToken());
        if (board[i][j] == 1) houses[houseCnt++] = new int[]{i, j};
        else if (board[i][j] == 2) chickens[chickCnt++] = new int[]{i, j};
      }
    }
    dfs(0, 0);
    System.out.print(ans);
  }
}
