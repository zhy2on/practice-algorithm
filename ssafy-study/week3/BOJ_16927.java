import java.io.*;
import java.util.*;

public class BOJ_16927 {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringBuilder sb = new StringBuilder();

  static int N, M, R;
  static int board[][] = new int[302][302];
  static int tmp[] = new int[302 * 2 + 302 * 2 - 4];
  static int dx[] = new int[] {0, 1, 0, -1}; // 시계방향
  static int dy[] = new int[] {1, 0, -1, 0}; // 시계방향

  static void restore(int layer, int n, int m, int size, int r) {
    int idx = r % size, bx = layer, by = layer, d = 0;
    for (int step = 0; step < size; ++step) {
        board[bx][by] = tmp[idx];
        idx = (idx + 1) % size;
        if (step == m - 1 || step == m - 1 + n - 1 || step == m - 1 + n - 1 + m - 1) ++d;
        bx += dx[d];
        by += dy[d];
    }
  }

  static void flatten(int layer, int n, int m, int size) {
    int idx = 0, bx = layer, by = layer, d = 0;
    for (int step = 0; step < size; ++step) {
      tmp[idx++] = board[bx][by];
      if (step == m - 1 || step == m - 1 + n - 1 || step == m - 1 + n - 1 + m - 1) ++d;
      bx += dx[d];
      by += dy[d];
    }
  }

  static boolean rotateLayer(int l, int r) { // layer, rotate
    int n = N - 2 * l;
    int m = M - 2 * l;

    if (n <= 0 || m <= 0) return false;

    int size = n * 2 + m * 2 - 4;

    flatten(l, n, m, size); // 평탄화
    restore(l, n, m, size, r); // 2차원 배열에 다시 넣기

    return true;
  }

  static void rotate() {
    int layer = 0;
    while (rotateLayer(layer, R)) ++layer;
  }
  
  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    R = Integer.parseInt(st.nextToken());

    for (int i = 0; i < N; ++i) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < M; ++j) board[i][j] = Integer.parseInt(st.nextToken());
    }

    rotate();

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) sb.append(board[i][j]).append(' ');
      sb.append('\n');
    }
    System.out.print(sb);
  }
}
