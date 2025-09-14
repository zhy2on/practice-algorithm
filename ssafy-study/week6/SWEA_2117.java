import java.io.*;
import java.util.*;

public class SWEA_2117 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, M, K;
  static List<int[]> homes = new ArrayList<>();

  static int cost(int k) {
    return k * k + (k - 1) * (k - 1);
  }

  static int run() {
    K = N + 1;
    while (cost(K) > homes.size() * M) --K; // K 최대부터

    while (true) {
      int best = 0;

      for (int r = 0; r < N; ++r) { // 각 좌표마다
        for (int c = 0; c < N; ++c) {
          int cnt = 0;
          for (int[] h : homes) {
            int d = Math.abs(h[0] - r) + Math.abs(h[1] - c); // 마름모꼴 안에 있는 집들
            if (d < K) ++cnt; // count 세고
          }
          best = Math.max(best, cnt); // 제일 큰 경우
        }
      }
      if (best * M >= cost(K)) return best; // 손해가 아니면 리턴
      --K;
    }
  }

  static void init() {
    homes.clear();
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 초기화
      init();

      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());

      for (int i = 0; i < N; ++i) {
        st = new StringTokenizer(br.readLine());
        for (int j = 0; j < N; ++j) {
          if (Integer.parseInt(st.nextToken()) == 1) homes.add(new int[]{i, j});
        }
      }

      // 실행
      sb.append('#').append(tc).append(' ').append(run()).append('\n');
    }
    System.out.print(sb);
  }
}
