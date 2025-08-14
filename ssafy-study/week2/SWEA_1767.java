import java.io.*;
import java.util.*;

public class SWEA_1767 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static final int X = 0, Y = 1;
  static int[][] xy = new int[12][2]; // 코어 좌표
  static int[] dir = new int[12];
  static int[] dx = new int[] {1, 0, -1, 0};
  static int[] dy = new int[] {0, -1, 0, 1};
  static int[][] board = new int[12][12];
  static int[][] board2 = new int[12][12];
  static int T, N, coreCnt, maxCore, ans;

  static int getLineLen(int x, int y, int dir) {
    int len = 0;
    while (true) {
      int nx = x + dx[dir], ny = y + dy[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= N) return len; // 마지막까지 도착했다면
      if (board2[nx][ny] == 1) return -1; // 마지막에 도달 못한 거라면
      x = nx;
      y = ny;
      ++len;
    }
  }

  static int setLine(int x, int y, int dir) {
    int len = getLineLen(x, y, dir);
    if (len < 0) return -1;
    for (int i = 0; i < len; ++i) {
      x += dx[dir];
      y += dy[dir];
      board2[x][y] = 1;
    }
    return len;
  }

  static void simulation() {
    int powerCore = 0, len = 0;
    // 시뮬레이션 돌릴 board2 초기화
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) board2[i][j] = board[i][j];

    // 정해진 방향에 따라 전선 깔기 시뮬레이션
    for (int coreIdx = 0; coreIdx < coreCnt; ++coreIdx) {
      if (dir[coreIdx] == -1) continue;
      int tmp = setLine(xy[coreIdx][X], xy[coreIdx][Y], dir[coreIdx]);
      if (tmp < 0) continue;
      ++powerCore;
      len += tmp;
    }

    // 값 업데이트
    if (powerCore > maxCore) {
      maxCore = powerCore;
      ans = len;
    } else if (powerCore == maxCore) {
      ans = Math.min(ans, len);
    }
  }

  static void dfs(int k) {
    if (k == coreCnt) { // 방향이 다 정해지면
      simulation(); // 시뮬레이션을 돌린다
      return;
    }

    if (dir[k] == -1) { // 이미 전원 연결된 코어는 그냥 건너뛴다
      dfs(k + 1);
      return;
    }
    for (int i = 0; i < 4; ++i) {
      dir[k] = i; // 방향을 정해준다
      dfs(k + 1);
    }
  }

  static void init() {
    coreCnt = 0;
    maxCore = 0;
    ans = Integer.MAX_VALUE;
  }

  static void print() {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) System.out.print(board[i][j] + " ");
      System.out.println();
    }
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
        for (int j = 0; j < N; ++j) {
          board[i][j] = st.nextToken().charAt(0) - '0';
          if (board[i][j] == 1) {
            if (i == N - 1 || j == N - 1) dir[coreCnt] = -1;
            else dir[coreCnt] = 0;
            xy[coreCnt++] = new int[] {i, j};
          }
        }
      }

      // 실행
      dfs(0);

      // 출력
      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }
    System.out.print(sb);
  }
}

/*
3
7
0 0 1 0 0 0 0
0 0 1 0 0 0 0
0 0 0 0 0 1 0
0 0 0 0 0 0 0
1 1 0 1 0 0 0
0 1 0 0 0 0 0
0 0 0 0 0 0 0
 */