import java.io.*;
import java.util.*;

public class BOJ_1654 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int K, N;
  static long[] line = new long[10000];

  static boolean enough(long x) { // 길이가 x일 때 만들 수 있는 라인이 N개 이상인지
    long cnt = 0;
    for (int i = 0; i < K; ++i) cnt += line[i] / x;
    return cnt >= N;
  }

  static long binarysearch() {
    long st = 1;
    long en = Integer.MAX_VALUE;

    while (st < en) {
      long mid = (st + en + 1) / 2;
      if (enough(mid)) st = mid;
      else en = mid - 1;
    }
    return st;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    K = Integer.parseInt(st.nextToken());
    N = Integer.parseInt(st.nextToken());
    for (int i = 0; i < K; ++i) {
      line[i] = Long.parseLong(br.readLine());
    }
    Arrays.sort(line, 0, K);
    System.out.print(binarysearch());
  }
}
