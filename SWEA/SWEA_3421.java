import java.util.*;
import java.io.*;

public class SWEA_3421 {

  static int T, N, M, ans;
  static StringBuilder sb = new StringBuilder();
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static boolean[][] notgood;
  static boolean[] isused = new boolean[21];

  static void dfs(int k) {
    if (k == N) {
      ++ans;
      return;
    }

    // 나를 안 쓰는 조합
    dfs(k + 1);

    // 나를 쓰는 조합
    // 나랑 안 맞는 애들이 이미 쓰였으면 더 들어가면 안 됨
    for (int i = 0; i < N; ++i) {
      if (notgood[k][i] && isused[i]) return;
    }
    isused[k] = true;
    dfs(k + 1);
    isused[k] = false;
  }

  static void init() {
    notgood = new boolean[N][N];
    for (int i = 0; i < N; ++i) {
      isused[i] = false;
    }
    ans = 0;
  }

  public static void main(String[] args) throws IOException {
    T = Integer.parseInt(br.readLine());

    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());

      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());

      // 초기화
      init();

      for (int i = 0; i < M; ++i) {
        st = new StringTokenizer(br.readLine());

        int a, b;
        a = Integer.parseInt(st.nextToken()) - 1;
        b = Integer.parseInt(st.nextToken()) - 1;

        notgood[a][b] = true;
        notgood[b][a] = true;
      }

      // 실행
      dfs(0);

      //출력
      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }
    System.out.print(sb);
  }
}
