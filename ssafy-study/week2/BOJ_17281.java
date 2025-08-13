import java.io.*;
import java.util.*;

public class BOJ_17281 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int N, ans;
  static int hit[][] = new int[50][9];
  static int hitter[] = new int[9];
  static boolean isused[] = new boolean[9];

  static int movePlayer(boolean[] base, int move) {
    int score = 0;

    // 홈에 선수 놓기
    base[0] = true;
    // move만큼 선수 이동
    for (int i = 3; i >= 0; --i) { // 3루부터 시작
      if (!base[i]) continue; // 해당 위치에 이동할 선수가 없으면 continue
      int next = i + move;
      if (next > 3) { // 홈 들어왔으니
        ++score; // score만 업데이트
      } else {
        base[next] = base[i]; // 진루한 베이스로 선수를 이동
      }
      base[i] = false; // 선수가 이동했으니 원래 있던 자리를 비움
    }

    return score;
  }

  static void updateAns() {
    int score = 0, inning = 0, idx = 0;

    while (inning < N) { // N개의 inning 동안
      int outCnt = 0; // 각 inning마다 outCnt 초기화
      boolean base[] = new boolean[4]; // base도 초기화

      while (outCnt < 3) { // 각 이닝은 outCnt가 3 미만일 동안만 실행해야 함
        int move = hit[inning][hitter[idx]];
        idx = (idx + 1) % 9; // idx 업데이트 주의!!!!
        if (move == 0) ++outCnt;
        else score += movePlayer(base, move);
      }
      ++inning;
    }

    ans = Math.max(ans, score);
  }

  static void dfs(int k) {
    if (k == 9) {
      updateAns();
      return;
    }
    if (k == 3) { // 4번째 선수는 0번으로 미리 고정되어 있음
      dfs(4);
      return;
    }
    for (int i = 1; i < 9; ++i) {
      if (isused[i]) continue;
      isused[i] = true;
      hitter[k] = i;
      dfs(k + 1);
      isused[i] = false;
    }
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    // 입력
    N = Integer.parseInt(br.readLine());
    for (int i = 0; i < N; ++i) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int j = 0; j < 9; ++j) hit[i][j] = Integer.parseInt(st.nextToken());
    }

    // 실행
    hitter[3] = 0; // 4번째 선수 0번으로 고정
    dfs(0);

    // 출력
    System.out.print(ans);
  }
}
