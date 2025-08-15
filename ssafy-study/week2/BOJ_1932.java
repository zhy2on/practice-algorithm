import java.io.*;
import java.util.*;

public class BOJ_1932 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int N, ans;
  static int[][] meet = new int[1000000][2];
  static int[] cnt = new int[1000000];

  static void run() {
    // 정렬 - 시작시간순. 시작시간이 같다면 종료시간이 더 빠른 걸로
    Arrays.sort(meet, 0, N, (a, b) -> {
      if (a[0] != b[0]) return a[0] - b[0];
      return a[1] - b[1];
    });

    // 해당 회의가 시작일 때의 최대 회의 개수 구하기
    cnt[0] = 1;
    for (int i = 1; i < N; ++i) {
      cnt[i] = 1;
      int j = i - 1;
      while (j >= 0 && meet[j][1] > meet[i][0]) --j;
      if (j == -1) continue;
      cnt[i] += cnt[j];
      ans = Math.max(ans, cnt[i]);
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
