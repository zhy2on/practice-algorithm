import java.io.*;
import java.util.*;

public class SWEA_3307_binarysearch_ver {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N;
  static int[] arr = new int[1002];

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      N = Integer.parseInt(br.readLine());
      StringTokenizer st = new StringTokenizer(br.readLine());

      int len = 0;
      int[] lis = new int[N];
      for (int i = 0; i < N; ++i) {
        arr[i] = Integer.parseInt(st.nextToken());

        int l = 0, r = len;
        while (l < r) {
          int m = (l + r) / 2;
          if (lis[m] < arr[i]) l = m + 1;
          else r = m;
        }
        lis[l] = arr[i];
        if (l == len) ++len;
      }

      sb.append('#').append(tc).append(' ').append(len).append('\n');
    }
    System.out.print(sb);
  }
}
