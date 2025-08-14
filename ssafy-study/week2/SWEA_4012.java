import java.io.*;
import java.util.*;

public class SWEA_4012 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, ans;
  static int[][] S = new int[16][16];
  static int[] aBase = new int[8];
  static int[] bBase = new int[8];

  static void updateAns() {
    int aS = 0, bS = 0;
    for (int i = 0; i < N / 2; ++i) {
      for (int j = 0; j < N / 2; ++j) {
        if (i == j) continue;
        aS += S[aBase[i]][aBase[j]];
        bS += S[bBase[i]][bBase[j]];
      }
    }
    ans = Math.min(ans, Math.abs(aS - bS));
  }

  static void dfs(int k, int aIdx, int bIdx) {
    if (k == N) {
      updateAns();
      return;
    }

    if (aIdx < N / 2) { // 내가 A에 들어가는 경우
      aBase[aIdx] = k;
      dfs(k + 1, aIdx + 1, bIdx);
    }
    if (bIdx < N / 2) { // 내가 B에 들어가는 경우
      bBase[bIdx] = k;
      dfs(k + 1, aIdx, bIdx + 1);
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
      dfs(0, 0, 0);

      // 출력
      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }
    System.out.print(sb);
  }
}
