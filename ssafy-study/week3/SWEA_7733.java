import java.io.*;
import java.util.*;

public class SWEA_7733 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N;
  static int cheese[][] = new int[102][102];
  static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  static int bfs(int x, int y, int day, boolean vis[][]) {
    if (vis[x][y] || cheese[x][y] <= day) return 0; // 이미 다른 그룹에 포함된 애거나 먹을 수 없다면

    Queue<int[]> q = new ArrayDeque<>();
    
    q.offer(new int[] {x, y});
    vis[x][y] = true;
    while (!q.isEmpty()) {
      int[] cur = q.poll();
      for (int d = 0; d < 4; ++d) {
        int nx = cur[0] + dir[d][0], ny = cur[1] + dir[d][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // OOB check
        if (vis[nx][ny] || cheese[nx][ny] <= day) continue; // vis check && eatable 체크
        q.offer(new int[] {nx, ny});
        vis[nx][ny] = true;
      }
    }
    return 1;
  }

  static int maxDay() {
    int d = 1;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) d = Math.max(d, cheese[i][j]);
    }
    return d;
  }

  static int run() {
    int ans = 1; // 무조건 한 덩어리 이상
    int maxD = maxDay(); // 가장 큰 일수까지만 보면 됨
    for (int day = 1; day <= maxD; ++day) {
      boolean vis[][] = new boolean[N][N];
      int group = 0;

      // 그룹 구하기
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) group += bfs(i, j, day, vis);
      }
      // 정답 업데이트
      ans = Math.max(ans, group);
    }
    return ans;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      N = Integer.parseInt(br.readLine());
      for (int i = 0; i < N; ++i) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int j = 0; j < N; ++j) cheese[i][j] = Integer.parseInt(st.nextToken());
      }

      // 실행 & 출력
      sb.append('#').append(tc).append(' ').append(run()).append('\n');
    }
    System.out.print(sb);
  }
}
