import java.io.*;
import java.util.*;

public class BOJ_1932 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int N, ans;
  static int[][] meet = new int[1000000][2];
  static boolean[] isused = new boolean[1000000];

  static void run() {
    // 정렬 - 시작시간순. 시작시간이 같다면 종료시간이 더 빠른 걸로
    Arrays.sort(meet, 0, N, (a, b) -> {
      if (a[0] != b[0]) return a[0] - b[0];
      return a[1] - b[1];
    });

    // 해당 회의가 시작일 때의 최대 회의 개수 구하기
    for (int i = 0; i < N; ++i) {
      int cnt = 1;

      if (isused[i]) continue;
      int cur = meet[i][1]; // 끝나는 시간
      int j = i + 1;
      while (true) {
        while (j < N && meet[j][0] < cur) ++j; // 시작시간이 끝나는 시간 이전이면 다음 걸 탐색
        if (j == N) break;
        cur = meet[j][1]; // 새로운 cur은 끝나는 시간
        isused[j] = true;
        ++cnt;
      }

      ans = Math.max(cnt, ans);
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
