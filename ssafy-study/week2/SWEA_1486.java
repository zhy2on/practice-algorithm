import java.io.*;
import java.util.*;

public class SWEA_1486 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, B, ans;
  static int[] h = new int[10000];

  static void dfs(int k, int height) { // 부분 집합
    if (height >= B) { // 합쳐진 키가 B이상이 돼버리는 순간
      ans = Math.min(ans, height - B); // ans를 업데이트하고
      return; // 탈출시킴. 더 들어가지 않음
    }
    if (k == N) return; // k가 N을 만나도 탈출시킴
    dfs(k + 1, height); // 나를 포함하지 않는 집합
    dfs(k + 1, height + h[k]); // 나를 포함하는 집합
  }

  static void init() {
    ans = Integer.MAX_VALUE;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());

    for (int tc = 1; tc <= T; ++tc) {  
      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      B = Integer.parseInt(st.nextToken());

      st = new StringTokenizer(br.readLine());
      for (int i = 0; i < N; ++i) h[i] = Integer.parseInt(st.nextToken());

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
