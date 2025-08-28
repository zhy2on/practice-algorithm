import java.io.*;
import java.util.*;

public class SWEA_4013 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, K;
  static int[][] magnet = new int[4][8];

  static int score() {
    int s = 0;
    s += (magnet[0][0] == 1) ? 1 : 0;
    s += (magnet[1][0] == 1) ? 2 : 0;
    s += (magnet[2][0] == 1) ? 4 : 0;
    s += (magnet[3][0] == 1) ? 8 : 0;
    return s;
  }

  static void run(int idx, int r) { // 자석 인덱스, 회전 방향
    int[] rotate = new int[4];
    rotate[idx] = r;
    // left
    for (int i = idx; i >= 1; --i) {
      if (magnet[i - 1][2] != magnet[i][6]) rotate[i - 1] = -rotate[i];
      else break;
    }
    // right
    for (int i = idx; i < 3; ++i) {
      if (magnet[i + 1][6] != magnet[i][2]) rotate[i + 1] = -rotate[i];
      else break;
    }

    for (int i = 0; i < 4; ++i) {
      if (rotate[i] == 1) {
        int tmp = magnet[i][7];
        for (int j = 7; j >= 1; --j) magnet[i][j] = magnet[i][j - 1];
        magnet[i][0] = tmp;
      } else if (rotate[i] == -1) {
        int tmp = magnet[i][0];
        for (int j = 0; j < 7; ++j) magnet[i][j] = magnet[i][j + 1];
        magnet[i][7] = tmp;
      }
    }
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      K = Integer.parseInt(br.readLine());
      for (int i = 0; i < 4; ++i) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int j = 0; j < 8; ++j) magnet[i][j] = Integer.parseInt(st.nextToken());
      }
      for (int i = 0; i < K; ++i) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int idx = Integer.parseInt(st.nextToken()) - 1; // 1-based -> 0-based
        int r = Integer.parseInt(st.nextToken());
        run(idx, r); // 실행
      }
      // 출력
      sb.append('#').append(tc).append(' ').append(score()).append('\n');
    }
    System.out.print(sb);
  }
}
