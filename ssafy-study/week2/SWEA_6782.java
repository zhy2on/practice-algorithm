import java.io.*;

public class SWEA_6782 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T;
  static long N, ans;

  static void run() {
    while (N > 2) {
      long rootN = (long)Math.sqrt(N);
      if (rootN * rootN == N) { // 제곱수면
        N = rootN;
        ++ans;
      } else { // 제곱수가 아니면
        ++rootN;
        long nextN = rootN * rootN; // 다음 제곱수를 찾아준다
        ans += nextN - N; // ans에 다음 제곱수까지 가게될 거리를 한번에 더해준다
        N = nextN;
      }
    }
  }

  static void init() {
    ans = 0;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 초기화
      init();
      // 입력
      N = Long.parseLong(br.readLine());
      // 실행
      run();
      // 출력
      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }
    System.out.print(sb);
  }
}
