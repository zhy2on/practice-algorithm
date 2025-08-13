import java.io.*;
import java.util.*;

public class SWEA_1952 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, ans;
  static int[] price = new int[4];
  static int[] plan = new int[12];

  static void dfs(int k, int total) {
    if (total >= ans) return; // 가지치기

    if (k >= 12) {
      ans = Math.min(ans, total);
      return;
    }

    // 1일 이용권
    dfs(k + 1, total + plan[k] * price[0]);

    // 1달 이용권
    dfs(k + 1, total + price[1]);

    // 3달 이용권
    dfs(k + 3, total + price[2]);
  }

  static void init() {
    ans = price[3]; // 1년 이용권 가격으로 초기화
  }
  
  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int i = 0; i < 4; ++i) price[i] = Integer.parseInt(st.nextToken());
      st = new StringTokenizer(br.readLine());
      for (int i = 0; i < 12; ++i) plan[i] = Integer.parseInt(st.nextToken());

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
