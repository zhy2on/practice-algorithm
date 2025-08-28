import java.io.*;
import java.util.*;

public class SWEA_5656 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, W, H, best, bricks;
  static int board[][] = new int[20][20];
  static int simul[][] = new int[20][20];
  static int[] selected = new int[10];
  static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  static void fall() { // 중력
    for (int col = 0; col < W; ++col) {
      int writeRow = H - 1;
      for (int row = H - 1; row >= 0; --row) {
        if (simul[row][col] != 0) {
          simul[writeRow--][col] = simul[row][col];
        }
      }
      for (int row = writeRow; row >= 0; --row) simul[row][col] = 0;
    }
  }

  static int bfs(int sx, int sy) {
    int cnt = 0;
    ArrayDeque<int[]> q = new ArrayDeque<>();
    // 처음 큐에 넣기
    q.offer(new int[]{sx, sy, simul[sx][sy]}); // {x, y, bomb(폭탄범위)}
    simul[sx][sy] = 0;

    // 다 깨고
    while (!q.isEmpty()) {
      int cur[] = q.poll();
      int x = cur[0], y = cur[1], bomb = cur[2];
      ++cnt; // q에서 꺼낸 애들 세면 깬 벽돌임

      for (int i = 1; i < bomb; ++i) { // 넣을 수 있는 애들 다 넣기
        for (int d = 0; d < 4; ++d) {
          int nx = x + dir[d][0] * i, ny = y + dir[d][1] * i;
          if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue; // OOB check
          if (simul[nx][ny] == 0) continue; // vis check
          q.offer(new int[]{nx, ny, simul[nx][ny]});
          simul[nx][ny] = 0;
        }
      }
    }

    // 중력
    fall();

    return cnt; // 몇 개 깼는지 돌려줌
  }

  static int targetRow(int c) {
    for (int r = 0; r < H; ++r) {
      if (simul[r][c] != 0) return r;
    }
    return -1;
  }

  static void dfs(int k, int bombed) {
    if (bombed == bricks) { // 다 깼으면
      best = bricks; // 조기 종료
      return;
    }

    if (k == N) {
      best = Math.max(best, bombed);
      return;
    }

    for (int c = 0; c < W; ++c) {
      int r = targetRow(c);
      if (r == -1) continue;

      // 백업
      int[][] backup = new int[H][W];
      for (int i = 0; i < H; ++i) System.arraycopy(simul[i], 0, backup[i], 0, W);

      dfs(k + 1, bombed + bfs(r, c));

      // 복구
      for (int i = 0; i < H; ++i) System.arraycopy(backup[i], 0, simul[i], 0, W);
    }
  }

  static void init() {
    best = 0;
    bricks = 0;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 초기화
      init();

      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      W = Integer.parseInt(st.nextToken());
      H = Integer.parseInt(st.nextToken());

      for (int i = 0; i < H; ++i) {
        st = new StringTokenizer(br.readLine());
        for (int j = 0; j < W; ++j) {
          board[i][j] = Integer.parseInt(st.nextToken());
          if (board[i][j] > 0) ++bricks;
        }
      }

      // 실행
      for (int i = 0; i < H; ++i) System.arraycopy(board[i], 0, simul[i], 0, W);
      dfs(0, 0);

      // 출력
      sb.append('#').append(tc).append(' ').append(bricks - best).append('\n');
    }
    System.out.print(sb);
  }
}
