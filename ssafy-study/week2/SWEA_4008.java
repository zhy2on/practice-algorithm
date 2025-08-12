import java.io.*;
import java.util.*;

public class SWEA_4008 {
  
  static int T, N, maxAns, minAns;
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int[] num = new int[12];
  static int[] sign =  new int[11];
  static int[] selected = new int[11];
  static boolean[] isused = new boolean[11];

  static void calc() {
    int ans = num[0];
    for (int i = 0; i < N - 1; ++i) {
      if (selected[i] == 0) {
        ans += num[i + 1];
      } else if (selected[i] == 1) {
        ans -= num[i + 1];
      } else if (selected[i] == 2) {
        ans *= num[i + 1];
      } else if (selected[i] == 3) {
        ans /= num[i + 1];
      }
    }
    maxAns = Math.max(ans, maxAns);
    minAns = Math.min(ans, minAns);
  }

  static void dfs(int k) {
    if (k == N - 1) {
      calc();
      return;
    }
    for (int i = 0; i < N - 1; ++i) {
      if (isused[i]) continue;
      isused[i] = true;
      selected[k] = sign[i];
      dfs(k + 1);
      isused[i] = false;
    }
  }

  static void init() {
    for (int i = 0; i < N - 1; ++i) isused[i] = false;
    maxAns = Integer.MIN_VALUE;
    minAns = Integer.MAX_VALUE;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new FileReader("ssafy-study/week2/sample_input.txt"));
    // br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 초기화
      init();

      // 입력
      N = Integer.parseInt(br.readLine());

      StringTokenizer st = new StringTokenizer(br.readLine());
      int signIdx = 0;
      for (int i = 0; i < 4; ++i) {
        int n = Integer.parseInt(st.nextToken());
        while (n-- > 0) sign[signIdx++] = i;
      }

      st = new StringTokenizer(br.readLine());
      for (int i = 0; i < N; ++i) num[i] = Integer.parseInt(st.nextToken());

      // 실행
      dfs(0);

      // 출력
      sb.append('#').append(tc).append(' ').append(maxAns - minAns).append('\n');
    }
    System.out.print(sb);
  }
}
