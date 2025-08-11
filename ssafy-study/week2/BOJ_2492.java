import java.io.*;
import java.util.*;

public class BOJ_2492 {

  static class Dot {
    int x, y;
    Dot(int x, int y) { this.x = x; this.y = y; }
  }

  static int N, M, T, K;
  static List<Dot> dots = new ArrayList<>();
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken()); // 지도 너비
    M = Integer.parseInt(st.nextToken()); // 지도 높이
    T = Integer.parseInt(st.nextToken()); // 금강석 개수
    K = Integer.parseInt(st.nextToken()); // 정사각형 변 길이

    for (int i = 0; i < T; i++) {
      st = new StringTokenizer(br.readLine());
      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());
      dots.add(new Dot(x, y));
    }

    int maxCount = 0;
    int ansX = 0, ansY = 0;

    // 모든 금강석 x좌표, y좌표를 왼쪽 위 꼭짓점 후보로
    for (Dot dx : dots) {
      int startX = dx.x;
      if (startX + K > N)
        startX = N - K; // 오른쪽 벗어나면 조정

      for (Dot dy : dots) {
        int startY = dy.y;
        if (startY + K > M)
          startY = M - K; // 위쪽 벗어나면 조정

        int cnt = 0;
        for (Dot d : dots) {
          if (startX <= d.x && d.x <= startX + K &&
              startY <= d.y && d.y <= startY + K) {
            cnt++;
          }
        }

        if (cnt > maxCount) {
          maxCount = cnt;
          ansX = startX;
          ansY = startY + K; // 문제에서 Y는 "위쪽" 좌표
        }
      }
    }

    System.out.println(ansX + " " + ansY);
    System.out.println(maxCount);
  }
}
