import java.io.*;
import java.util.*;

public class SWEA_4014 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, X;
  static int[][] board = new int[25][25];

  static int checkLine(int[] arr) {
    boolean[] used = new boolean[N];

    for (int i = 0; i < N - 1; ++i) {
      if (arr[i] == arr[i + 1]) continue;

      int diff = arr[i + 1] - arr[i];

      if (diff == 1) { // 오르막
        for (int k = i; k > i - X; --k) { // 나로 들어오는 곳에 경사로 설치
          if (k < 0) return 0;
          if (used[k]) return 0;
          used[k] = true;
        }
      } else if (diff == -1) { // 내리막
        for (int k = i + 1; k < i + 1 + X; ++k) { // 나에서 나가는 곳에 경사로 설치
          if (k >= N) return 0;
          if (used[k]) return 0;
          used[k] = true;
        }
      } else return 0; // 차이가 1보다 크면
    }
    return 1;
  }

  static int run() {
    int ans = 0;
    int[] line = new int[N];
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) line[j] = board[i][j];
      ans += checkLine(line);
    }
    for (int j = 0; j < N; ++j) {
      for (int i = 0; i < N; ++i) line[i] = board[i][j];
      ans += checkLine(line);
    }
    return ans;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      X = Integer.parseInt(st.nextToken());

      for (int i = 0; i < N; ++i) {
        st = new StringTokenizer(br.readLine());
        for (int j = 0; j < N; ++j) board[i][j] = Integer.parseInt(st.nextToken());
      }

      // 실행 & 출력
      sb.append('#').append(tc).append(' ').append(run()).append('\n');
    }
    System.out.print(sb);
  }
}
