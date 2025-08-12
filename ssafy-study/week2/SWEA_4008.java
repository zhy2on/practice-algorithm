import java.io.*;
import java.util.*;

public class SWEA_4008 {
  
  static int T, N, maxAns, minAns;
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int[] num = new int[12];
  static int[] operator = new int[4];

  static void dfs(int k, int result) {
    if (k == N - 1) {
      minAns = Math.min(result, minAns);
      maxAns = Math.max(result, maxAns);
      return;
    }
    for (int i = 0; i < 4; ++i) { // 각 연산자 중 하나를 사용
      if (operator[i] == 0) continue;

      --operator[i]; // 연산자 사용
      if (i == 0) {
        dfs(k + 1, result + num[k + 1]);
      } else if (i == 1) {
        dfs(k + 1, result - num[k + 1]);
      } else if (i == 2) {
        dfs(k + 1, result * num[k + 1]);
      } else if (i == 3) {
        dfs(k + 1, result / num[k + 1]);
      }
      ++operator[i]; // 다시 복귀
    }
  }

  static void init() {
    maxAns = Integer.MIN_VALUE;
    minAns = Integer.MAX_VALUE; 
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 초기화
      init();

      // 입력
      N = Integer.parseInt(br.readLine());

      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int i = 0; i < 4; ++i) operator[i] = Integer.parseInt(st.nextToken());

      st = new StringTokenizer(br.readLine());
      for (int i = 0; i < N; ++i) num[i] = Integer.parseInt(st.nextToken());

      // 실행
      dfs(0, num[0]);

      // 출력
      sb.append('#').append(tc).append(' ').append(maxAns - minAns).append('\n');
    }
    System.out.print(sb);
  }
}
