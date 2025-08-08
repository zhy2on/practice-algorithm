import java.io.*;
import java.util.*;

public class SWEA_1210 {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringBuilder sb = new StringBuilder();
  static final int SIZE = 100;
  static int[][] board = new int[SIZE][SIZE];
  static int[] cur;

  static final int X = 0;
  static final int Y = 1;

  static boolean OOB(int x, int y) {
    return x < 0 || x >= SIZE || y < 0 || y >= SIZE;
  }

  static void move_dy(int dy) {
    while (true) {
      int nearY = cur[Y] + dy;
      if (OOB(cur[X], nearY) || board[cur[X]][nearY] != 1) return;
      cur[Y] = nearY;
    }
  }

  static int get_ans() {
    // 도착점(start)부터 거슬러 올라가며
    while (true) {
      // 좌우 방향이 이동 가능하다면 좌우 이동
      if (!OOB(cur[X], cur[Y] - 1) && board[cur[X]][cur[Y] - 1] == 1) move_dy(-1);
      else if (!OOB(cur[X], cur[Y] + 1) && board[cur[X]][cur[Y] + 1] == 1) move_dy(1);
      cur[X] -= 1; // 위로 한 칸은 무조건 이동
      if (cur[X] == 0) return cur[Y];
    }
  }

  public static void main(String[] args) throws IOException {
    for (int tc = 1; tc <= 10; ++tc) {
      br.readLine(); // 테스트 케이스 번호 한 줄 건너 뛰기

      // 입력
      for (int row = 0; row < SIZE; ++row) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int col = 0; col < SIZE; ++col) {
          board[row][col] = Integer.parseInt(st.nextToken());
          if (board[row][col] == 2) cur = new int[] {row, col};
        }
      }

      // 실행
      sb.append('#').append(tc).append(' ').append(get_ans()).append('\n');
    }

    // 최종 출력
    System.out.println(sb);
  }
}
