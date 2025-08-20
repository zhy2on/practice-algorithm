import java.io.*;
import java.util.*;

public class BOJ_2636 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int N, M, lastCnt, t;
  static int[][] cheese = new int[100][100];
  static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  static int bfs() {
    Queue<int[]> q = new ArrayDeque<>();
    boolean[][] vis = new boolean[100][100];
    int cnt = 0;
    q.offer(new int[] {0, 0}); // x, y
    vis[0][0] = true;

    while (!q.isEmpty()) {
      int[] cur = q.poll();
      
      for (int d = 0; d < 4; ++d) {
        int nx = cur[0] + dir[d][0], ny = cur[1] + dir[d][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue; // OOB check
        if (vis[nx][ny]) continue;

        vis[nx][ny] = true;
        if (cheese[nx][ny] == 1) { // 공기랑 맞닿아 있는 치즈면
          cheese[nx][ny] = 0; // 녹이고
          ++cnt; // 큐엔 넣지 않음. 대신 카운트
        } else { // 공기라면
          q.offer(new int[] {nx, ny}); // 큐에 넣음
        }
      }
    }
    return cnt;
  }

  static void run() {
    while (true) {
      int n = bfs();
      if (n <= 0) return;
      ++t;
      lastCnt = n;
    }
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    for (int i = 0; i < N; ++i) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < M; ++j) cheese[i][j] = Integer.parseInt(st.nextToken());
    }

    run();

    System.out.println(t);
    System.out.println(lastCnt);
  }
}
