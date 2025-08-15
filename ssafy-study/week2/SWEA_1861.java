import java.io.*;
import java.util.*;

public class SWEA_1861 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, ansVal, ansCnt;
  static int[][] room = new int[1000][1000];
  static int[] dx = new int[] {1, 0, -1, 0};
  static int[] dy = new int[] {0, -1, 0, 1};

  static void updateAns(int startVal, int cnt) {
    if (cnt > ansCnt) {
      ansCnt = cnt;
      ansVal = startVal;
    } else if (cnt == ansCnt) {
      ansVal = Math.min(ansVal, startVal);
    }
  }

  static void bfs(boolean[][] vis, int x, int y) { // 나와 연결되는 방을 모두 방문
    int cnt = 0, startVal = room[x][y];
    Queue<int[]> q = new LinkedList<>();
    q.add(new int[] {x, y, startVal});
    vis[x][y] = true;
    while (!q.isEmpty()) {
      int[] cur = q.poll();
      ++cnt;
      for (int d = 0; d < 4; ++d) {
        int nx = cur[0] + dx[d], ny = cur[1] + dy[d];
        int curVal = room[cur[0]][cur[1]];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || vis[nx][ny]) continue; // OOB check, visited check
        if (room[nx][ny] != curVal + 1 && room[nx][ny] != curVal - 1) continue; // 연결된 애 아니면 continue
        if (room[nx][ny] == curVal - 1) startVal = room[nx][ny]; // 가려는 애가 -1인 애였으면 startVal 갱신
        q.add(new int[] {nx, ny});
        vis[nx][ny] = true;
      }
    }
    updateAns(startVal, cnt);
  }

  static void run() {
    boolean[][] vis = new boolean[1000][1000];
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (!vis[i][j]) bfs(vis, i, j); // 각 점마다 bfs 해줘야 됨
      }
    }
  }

  static void init() {
    ansVal = Integer.MAX_VALUE;
    ansCnt = 0;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 초기화
      init();
      // 입력
      N = Integer.parseInt(br.readLine());
      for (int i = 0; i < N; ++i) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int j = 0; j < N; ++j) room[i][j] = Integer.parseInt(st.nextToken());
      }
      // 실행
      run();
      //출력
      sb.append('#').append(tc).append(' ').append(ansVal).append(' ').append(ansCnt).append('\n');
    }
    System.out.print(sb);
  }
}
