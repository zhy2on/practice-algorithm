import java.io.*;
import java.util.*;

public class SWEA_5644 {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringBuilder sb = new StringBuilder();
  static int[] dx = {0, 0, 1, 0, -1}; // 정지 상 우 하 좌
  static int[] dy = {0, -1, 0, 1, 0};
  static int[] moveA = new int[102];
  static int[] moveB = new int[102];
  static int[][] BC = new int[12][4]; // bc의 x, y, C, P를 차례로 저장
  static int T, M, A, ax, ay, bx, by, ans; // M: 이동 A: 충전기 개수

  static void move(int ad, int bd) {
    ax += dx[ad]; ay += dy[ad];
    bx += dx[bd]; by += dy[bd];
  }

  static int useBC() { // 범위 내인 충전기에서 충전. 사용자 2명밖에 안 되니까 그냥 2중 포문 돌기
    int maxp = 0;
    // a가 쓰는 충전기
    for (int i = 0; i < A; ++i) { // 충전기 돌면서 사용자가 범위 안인지 확인
      int x1 = BC[i][0], y1 = BC[i][1], C1 = BC[i][2], P1 = BC[i][3];
      // b가 쓰는 충전기
      for (int j = 0; j < A; ++j) {
        int power = 0;
        int x2 = BC[j][0], y2 = BC[j][1], C2 = BC[j][2], P2 = BC[j][3];
        boolean isAPossible = (Math.abs(ax - x1) + Math.abs(ay - y1)) <= C1;
        boolean isBPossible = (Math.abs(bx - x2) + Math.abs(by - y2)) <= C2;

        if (isAPossible) power += P1;
        if (isBPossible) power += P2;
        if (isAPossible && isBPossible && i == j) power /= 2; // 같은 거 썼었다면
        maxp = Math.max(maxp, power);
      }
    }
    return maxp; // 해당 자리에서 가장 많은 충전량 리턴
  }

  static void run() {
    for (int m = 0; m <= M; ++m) {
      // 범위 내인 충전기에서 충전
      ans += useBC();
      // 이동
      move(moveA[m], moveB[m]);
    }
  }

  static void init() {
    ax = 0; ay = 0;
    bx = 9; by = 9;
    ans = 0;
  }

  public static void main(String[] args) throws IOException {
    T = Integer.parseInt(br.readLine());

    for (int tc = 1; tc <= T; ++tc) {
      // 초기화
      init();

      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      M = Integer.parseInt(st.nextToken());
      A = Integer.parseInt(st.nextToken());

        // A 이동 정보
      st = new StringTokenizer(br.readLine());
      for (int i = 0; i < M; ++i) moveA[i] = Integer.parseInt(st.nextToken());
        // B 이동 정보
      st = new StringTokenizer(br.readLine());
      for (int i = 0; i < M; ++i) moveB[i] = Integer.parseInt(st.nextToken());
      
        // 충전기 정보
      for (int i = 0; i < A; ++i) {
        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken()) - 1; // 1-based -> 0-based로 변경
        int y = Integer.parseInt(st.nextToken()) - 1; // 1-based -> 0-based로 변경
        int C = Integer.parseInt(st.nextToken()); // C
        int P = Integer.parseInt(st.nextToken()); // P
        BC[i] = new int[] {x, y, C, P};
      }

      // 실행
      run();

      // 출력
      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }
    System.out.print(sb);
  }
}
