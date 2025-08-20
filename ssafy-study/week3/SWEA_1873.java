import java.io.*;
import java.util.*;

public class SWEA_1873 {

  static final char FIELD = '.', BRICK = '*', STEEL = '#', WATER = '-';
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, H, W, N, tx, ty; // tx, ty: 전차 위치
  static char board[][] = new char[22][22];
  static char cmd[] = new char[102];
  static int dir[][] = new int[][] {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상 하 좌 우

  static boolean OOB(int x, int y) { // out of bounds
    return x < 0 || x >= H || y < 0 || y >= W;
  }

  static int DIRNUM(char c) {
    if (c == '^' || c == 'U') return 0;
    if (c == 'v' || c == 'D') return 1;
    if (c == '<' || c == 'L') return 2;
    if (c == '>' || c == 'R') return 3;
    return 4;
  }

  static char DIRCHAR(int n) {
    if (n == 0) return '^';
    if (n == 1) return 'v';
    if (n == 2) return '<';
    if (n == 3) return '>';
    return 0;
  }

  static void shoot(int d) {
    int nx = tx, ny = ty;
    while (true) {
      nx += dir[d][0]; // while 업데이트
      ny += dir[d][1];
      if (OOB(nx, ny)) return;
      if ((board[nx][ny] == BRICK) || (board[nx][ny] == STEEL)) {
        if (board[nx][ny] == BRICK) board[nx][ny] = FIELD;
        return;
      }
    }
  }

  static void move(int d) { // 한 칸 이동
    int nx = tx + dir[d][0], ny = ty + dir[d][1];
    board[tx][ty] = '.'; // 지금 위치를 평지로 바꿈
    if (OOB(nx, ny) || (board[nx][ny] != FIELD)) { // 이동 못 하면 그대로
      nx = tx;
      ny = ty;
    }
    board[nx][ny] = DIRCHAR(d); // 다음 위치를 d로 바꿈
    tx = nx; // 전차의 새 위치 업데이트
    ty = ny;
  }

  static void run() {
    for (int i = 0; i < N; ++i) {
      if (cmd[i] == 'S') shoot(DIRNUM(board[tx][ty]));
      else move(DIRNUM(cmd[i])); // S 아니면 디렉션임
    }
  }

  static boolean isTank(char c) {
    return c == '^' || c == 'v' || c == '<' || c == '>';
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      H = Integer.parseInt(st.nextToken());
      W = Integer.parseInt(st.nextToken());

      for (int i = 0; i < H; ++i) {
        board[i] = br.readLine().toCharArray();
        for (int j = 0; j < W; ++j) {
          if (isTank(board[i][j])) {
            tx = i;
            ty = j;
          }
        }
      }

      N = Integer.parseInt(br.readLine());
      cmd = br.readLine().toCharArray();

      // 실행
      run();

      // 출력
      sb.append('#').append(tc).append(' ');
      for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) sb.append(board[i][j]);
        sb.append('\n');
      }
    }
    System.out.print(sb);
  }
}
