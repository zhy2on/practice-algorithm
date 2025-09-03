import java.io.*;
import java.util.*;

public class BOJ_1927 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int N;
  static PriorityQueue<Integer> pq = new PriorityQueue<>();

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    N = Integer.parseInt(br.readLine());
    for (int i = 0; i < N; ++i) {
      int x = Integer.parseInt(br.readLine());
      if (x == 0) {
        Integer n = pq.poll();
        if (n == null) sb.append(0).append('\n');
        else sb.append(n).append('\n');
      }
      else pq.offer(x);
    }
    System.out.print(sb);
  }
}
