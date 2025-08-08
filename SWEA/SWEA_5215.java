import java.io.*;
import java.util.*;

public class SWEA_5215 {

  static final int SCORE = 0;
  static final int CALO = 1;

  static int T, N, L, ans;
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringBuilder sb = new StringBuilder();
  static int[][] hamburgers = new int[1001][1001];

  static void subset(int k, int score, int calo) {
    if (calo > L) return; // 제한 칼로리를 넘어가면 리턴

    if (k == N) {
      ans = Math.max(ans, score); // depth N까지 들어왔다면 ans를 업데이트
      return;
    }

    subset(k + 1, score, calo); // 나를 포함하지 않는 경우
    subset(k + 1, score + hamburgers[k][SCORE], calo + hamburgers[k][CALO]); // 나를 포함하는 경우
  }

  static void init() {
    ans = 0;
  }

  public static void main(String[] args) throws IOException {
    T = Integer.parseInt(br.readLine());

    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      L = Integer.parseInt(st.nextToken());

      for (int i = 0; i < N; ++i) {
        st = new StringTokenizer(br.readLine());
        int score = Integer.parseInt(st.nextToken());
        int calo = Integer.parseInt(st.nextToken());
        hamburgers[i] = new int[] {score, calo};
      }

      // 초기화
      init();

      // 실행
      subset(0, 0, 0);

      // 출력
      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }
    System.out.print(sb);
  }
}
