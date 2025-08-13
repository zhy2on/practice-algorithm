import java.io.*;

public class SWEA_2805 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, ans;
  static int[][] farm = new int[49][49];

  static int getSum(int[] arr, int idx, int cnt) {
    int sum = 0;
    while (cnt-- > 0) sum += arr[idx++];
    return sum;
  }

  static void getProfit() {
    for (int i = 1; i <= N / 2; ++i) { // 가운데 줄을 기준으로 대칭으로 합을 구한다
      ans += getSum(farm[N / 2 - i], i, N - i * 2);
      ans += getSum(farm[N / 2 + i], i, N - i * 2);
    }
    ans += getSum(farm[N / 2], 0, N); // 가운데 줄
  }

  static void init() {
    ans = 0;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      N = Integer.parseInt(br.readLine());
      for (int i = 0; i < N; ++i) {
        char[] line = br.readLine().toCharArray();
        for (int j = 0; j < N; ++j) farm[i][j] = line[j] - '0';
      }
      // 초기화
      init();
      // 실행
      getProfit();
      // 출력
      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }
    System.out.print(sb);
  }
}
