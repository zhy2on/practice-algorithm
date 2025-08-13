import java.io.*;
import java.util.*;

public class SWEA_4796 {

  static StringBuilder sb = new StringBuilder();
  static int T, N;

  public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(System.in);

    T = sc.nextInt();
    for (int tc = 1; tc <= T; ++tc) {
      // 변수 선언 및 초기화 (ascending 찾기 위해 before_h 초기값은 INTEGER_MAX로 초기화)
      int ans = 0, i = -1, k = -1, N, before_h = Integer.MAX_VALUE, cur_h;

      N = sc.nextInt();

      for (int n = 0; n < N; ++n) {
        cur_h = sc.nextInt();
        if (i == -1) { // i가 안 정해졌다는 건 아직 오름차순을 한 번도 만나지 못한 것.
          if (before_h < cur_h) { // 오름차순 만나면
            i = n - 1; // i 업데이트
          }
        } else if (k == -1) { // k가 안 정해졌다는 건 꺾이기 전이라는 것. 오름차순 상태라는 것
          if (before_h > cur_h) { // 꺾이는 지점을 찾았다
            k = n - 1; // k 업데이트
          }
        } else { // k가 정해졌다는 건 꺾인 다음이라는 것. 내림차순 상태라는 것
          if (before_h < cur_h) { // 다시 오름차순이 시작이라는 건? 구간을 찾았다는 것
            ans += (k - i) * (n - 1 - k); // ans 업데이트
            k = -1; // k는 다시 정해지지 않은 상태로 초기화
            i = n - 1; // i는 새로운 시작점으로 업데이트
          }
        }
        before_h = cur_h;
      }
      // k가 정해진 상태라면 == 꼭대기를 찾았는데 마지막 인덱스에 도달해서 그냥 끝나버린 것. 해당 구간을 더해준다.
      if (k != -1) ans += (k - i) * (N - 1 - k);

      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }
    System.out.print(sb);
  }
}
