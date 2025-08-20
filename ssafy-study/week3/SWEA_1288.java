import java.io.*;

public class SWEA_1288 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, base;

  static int run() {
    final int FULL = (1 << 10) - 1; // 0~9 bit
    int mask = 0;
    for (int n = 1; ; ++n) {
      int x = base * n;
      int tmp = x;
      while (tmp > 0) {
        int bit = 1 << (tmp % 10);
        mask |= bit;
        if (mask == FULL) return x;
        tmp /= 10;
      }
    }
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      base = Integer.parseInt(br.readLine());
      sb.append('#').append(tc).append(' ').append(run()).append('\n');
    }
    System.out.print(sb);
  }
}
