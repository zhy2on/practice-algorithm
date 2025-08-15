import java.io.*;
import java.util.*;

public class BOJ_1932 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int N, ans;
  static List<Meeting> meetList = new ArrayList<>();
  static int[] cnt = new int[1000000];

  static class Meeting {
    int start, end;
    Meeting(int start, int end) { this.start = start; this.end = end; }
  }

  static void run() {
    // 정렬 - 시작시간순. 시작시간이 같다면 종료시간이 더 빠른 걸로
    Collections.sort(meetList, (m1, m2) -> {
      if (m1 != m2) return m1.start - m2.start;
      return m1.end - m2.end;
    });

    // 해당 회의가 시작일 때의 최대 회의 개수 구하기
    for (int i = 0; i < N; ++i) {
      int cur = meetList.get(i).end;
      int j = i + 1;
      while (true) {
        while (j < N && meetList.get(j).start < cur) ++j;
        if (j == N) break;
        cur = meetList.get(j).end;
        ++cnt[i];
      }
    }

    // max값으로 업데이트
    ans = Arrays.stream(cnt).max().getAsInt() + 1;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    N = Integer.parseInt(br.readLine());
    for (int i = 0; i < N; ++i) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int start = Integer.parseInt(st.nextToken());
      int end = Integer.parseInt(st.nextToken());
      meetList.add(new Meeting(start, end));
    }

    run();

    System.out.print(ans);
  }
}
