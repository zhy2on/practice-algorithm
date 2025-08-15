import java.io.*;
import java.util.*;

public class BOJ_1932 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int N, ans;
  static int[][] meet = new int[1000000][2];

  static void run() {
    // 정렬 - 끝나는 시간이 기준이 돼야함. 시작시간이 끝나는 시간에 종속되어 있기 때문!
    Arrays.sort(meet, 0, N, (a, b) -> {
      // 먼저 종료시간 순으로 정렬
      if (a[1] != b[1]) return a[1] - b[1];
      // 그 다음 시작시간 순으로 정렬 - 종료시간과 시작시간이 같을 수 있기 때문에 필요하다!!
      // ex) [(2, 2), (1, 2)] 가 있을 때
      // (1, 2)를 사용하고 (2, 2)를 사용할 수 있기 때문에 최대 2개를 사용할 수 있지만
      // 시작시간 기준으로 정렬이 적용되지 않았다면 (2, 2)를 먼저 선택해버려서 (1, 2)가 선택되지 않는다
      return a[0] - b[0];
    });

    int cur = 0;
    for (int i = 0; i < N; ++i) {
      if (meet[i][0] < cur) continue;
      ++ans;
      cur = meet[i][1];
    }
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    N = Integer.parseInt(br.readLine());
    for (int i = 0; i < N; ++i) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int start = Integer.parseInt(st.nextToken());
      int end = Integer.parseInt(st.nextToken());
      meet[i] = new int[]{start, end};
    }

    run();

    System.out.print(ans);
  }
}
