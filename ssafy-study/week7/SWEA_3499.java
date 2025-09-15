import java.io.*;
import java.util.*;

public class SWEA_3499 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N;
  static String[] strs = new String[1002];

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      int N = Integer.parseInt(br.readLine());
      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int i = 0; i < N; ++i) strs[i] = st.nextToken();

      int mid = (N + 1) / 2;
      sb.append('#').append(tc);
      for (int k = 0; k < mid; ++k) {
        sb.append(' ').append(strs[k]);
        int r = k + mid;
        if (r < N) sb.append(' ').append(strs[r]);
      }
      sb.append('\n');
    }
    System.out.print(sb);
  }
}
