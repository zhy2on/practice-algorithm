import java.io.*;
import java.util.*;

public class SWEA_5658 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, K;
  static char[] number = new char[30];
  static int[] candidate = new int[30]; // 최대 28개. 각 숫자 0~16^7. int 범위 안임.

  static int n16(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return 10 + c - 'A';
  }
  
  static int num(int start, int len) { // start부터 len까지 10진수로 돌려주기
    int n = 0;
    for (int i = 0; i < len; ++i) {
      n = (n * 16 + n16(number[(start + i) % N]));
    }
    return n;
  }

  static int run() {
    int idx = 0;
    for (int i = 0; i < N / 4; ++i) {
      int start = (N - 1 - i);
      for (int j = 0; j < 4; ++j) {
        candidate[idx++] = -num(start + (j * N / 4), N / 4); // 정렬할 때 내림차순 정렬되게 -로 받아버리기
      }
    }

    Arrays.sort(candidate, 0, N); // 정렬하고
    int rank = 1;
    for (int i = 0; i < N; ++i) {
      if (rank == K) return -candidate[i]; // rank이면 return
      if (i == 0 || candidate[i] != candidate[i - 1]) ++rank; // 앞이랑 중복 아닐 때만 rank 올려줌
    }
    return -1;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      K = Integer.parseInt(st.nextToken());
      number = br.readLine().toCharArray();

      // 실행 & 출력
      sb.append('#').append(tc).append(' ').append(run()).append('\n');
    }
    System.out.print(sb);
  }
}
