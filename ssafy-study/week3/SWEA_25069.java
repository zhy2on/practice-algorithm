import java.io.*;
import java.util.*;

public class SWEA_25069 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, M, K;
  static boolean arr[] = new boolean[510];

  static int run() {
    int score = 0;
    int cut = N - M; // 가능한 cut 개수

    int hit = 0;
    for (int i = N - 1; i >= 0; --i) { // 뒤에서부터
      ++hit;
      if (((hit % K) == 0 || i <= cut) && cut > 0) { // hit면 끊어줌. 또는 i가 cut개수 이하이면 그냥 cut을 다 써줌
        --cut;
        arr[i] = false;
      } else arr[i] = true;
    }

    hit = 0;
    for (int i = 0; i < N; ++i) { // 앞에서부터 점수 계산
      if (arr[i]) {
        ++hit;
        if ((hit % K) == 0) score = (score + 1) * 2;
        else score = score + 1;
      } else hit = 0;
    }
    return score;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());
      K = Integer.parseInt(st.nextToken());

      // 출력
      sb.append('#').append(tc).append(' ').append(run()).append('\n');
    }
    System.out.print(sb);
  }
}
