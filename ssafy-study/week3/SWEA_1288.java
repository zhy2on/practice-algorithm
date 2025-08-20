import java.io.*;

public class SWEA_1288 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, cnt, base, next;
  static boolean[] see = new boolean[10];

  static boolean count() {
    int tmp = next;
    while (tmp > 0) {
      if (!see[tmp % 10]) {
        ++cnt;
        see[tmp % 10] = true;
        if (cnt == 10) return true;
      }
      tmp /= 10;
    }
    return false;
  }
  
  static int run() {
    while (true) {
      next += base;
      if (count()) return next;
    }
  }

  static void init() {
    for (int i = 0; i < 10; ++i) see[i] = false;
    cnt = 0;
    next = 0;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      init();
      base = Integer.parseInt(br.readLine());
      sb.append('#').append(tc).append(' ').append(run()).append('\n');
    }
    System.out.print(sb);
  }
}
