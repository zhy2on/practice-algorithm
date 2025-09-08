import java.io.*;
import java.util.*;

public class BOJ_2655 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int N;
  static Brick[] bricks = new Brick[102];

  static class Brick implements Comparable<Brick> {
    int id, b, h, w; // bottom, height, weight
    public Brick(int id, int b, int h, int w) {
      this.id = id; this.b = b; this.h = h; this.w = w;
    }
    public int compareTo(Brick o) {
      return Integer.compare(o.b, this.b);
    }
  }

  static void run() {
    // 너비순 정렬
    Arrays.sort(bricks, 1, N + 1);

    // 그 다음 무게 LIS 찾기
    int[] dp = new int[N + 1];
    int[] path = new int[N + 1];
    int[] size = new int[N + 1];

    for (int i = 1; i <= N; ++i) {
      dp[i] = bricks[i].h;
      path[i] = -1; // 이전 탑 기록용
      size[i] = 1; // 사이즈 기록용
      for (int j = 1; j < i; ++j) {
        if (bricks[i].w < bricks[j].w) {
          if (dp[j] + bricks[i].h > dp[i]) {
            dp[i] = dp[j] + bricks[i].h;
            path[i] = j;
            size[i] = size[j] + 1;
          }
        }
      }
    }

    // 가장 높은 탑 구하고 거기부터 path 구해가기
    int maxI = 0, maxH = 0;
    for (int i = 1; i <= N; ++i) {
      if (dp[i] > maxH) {
        maxH = dp[i];
        maxI = i;
      }
    }

    sb.append(size[maxI]).append('\n');
    while (true) {
      sb.append(bricks[maxI].id).append('\n');
      maxI = path[maxI];
      if (maxI == -1) return;
    }
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    N = Integer.parseInt(br.readLine());
    for (int i = 1; i <= N; ++i) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      int b = Integer.parseInt(st.nextToken());
      int h = Integer.parseInt(st.nextToken());
      int w = Integer.parseInt(st.nextToken());
      bricks[i] = new Brick(i, b, h, w);
    }
    run();
    System.out.print(sb);
  }
}
