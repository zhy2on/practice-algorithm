import java.io.*;
import java.util.*;

public class SWEA_1494 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N;
  static long[][] jirung = new long[22][2];
  static long ans;

  // idx: 현재 보고 있는 인덱스
  // picked: 지금까지 +로 고른 개수
  // vx, vy: 지금까지의 벡터 합
  static void dfs(int idx, int picked, long vx, long vy) {
    /// 가지치기 1: +를 너무 많이 선택
    if (picked > N / 2) return;
    // 가지치기 2: 남은 점으로 +를 N/2까지 못 채우는 경우
    int remain = N - idx;
    if (picked + remain < N / 2) return;

    if (idx == N) {
      if (picked == N / 2) {
        long val = vx * vx + vy * vy;
        if (val < ans) ans = val;
      }
      return;
    }

    // idx를 +로 선택: (x,y) 더하기
    dfs(idx + 1, picked + 1, vx + jirung[idx][0], vy + jirung[idx][1]);

    // idx를 -로 선택: (-x,-y) 더하기
    dfs(idx + 1, picked, vx - jirung[idx][0], vy - jirung[idx][1]);
  }

  static void init() {
    ans = Long.MAX_VALUE;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 초기화
      init();

      // 입력
      N = Integer.parseInt(br.readLine());
      for (int i = 0; i < N; ++i) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        jirung[i][0] = Long.parseLong(st.nextToken());
        jirung[i][1] = Long.parseLong(st.nextToken());
      }

      // 실행
      dfs(1, 1, jirung[0][0], jirung[0][1]);

      //출력
      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }
    System.out.print(sb);
  }
}
