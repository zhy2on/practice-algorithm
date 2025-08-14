import java.io.*;
import java.util.*;

public class SWEA_4012 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, ans;
  static int[][] S = new int[16][16];
  static boolean[] isA = new boolean[16];

  static void updateAns() {
    int aS = 0, bS = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (i == j) continue;
        if (isA[i] && isA[j]) aS += S[i][j];
        if (!isA[i] && !isA[j]) bS += S[i][j]; 
      }
    }
    ans = Math.min(ans, Math.abs(aS - bS));
  }

  static void dfs(int k, int st) { // 식재료 N/2를 뽑음
    if (k == N / 2) {
      updateAns();
      return;
    }

    for (int i = st; i < N; ++i) {
      isA[i] = true;
      dfs(k + 1, i + 1);
      isA[i] = false;
    }
  }

  static void init() {
    ans = Integer.MAX_VALUE;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      N = Integer.parseInt(br.readLine());
      for (int i = 0; i < N; ++i) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int j = 0; j < N; ++j) S[i][j] = Integer.parseInt(st.nextToken());
      }

      // 초기화
      init();

      // 실행
      dfs(0, 0);

      // 출력
      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }
    System.out.print(sb);
  }
}
