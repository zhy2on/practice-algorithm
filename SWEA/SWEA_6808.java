import java.io.*;
import java.util.*;

public class SWEA_6808 {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringBuilder sb = new StringBuilder();
  static int T, WIN, LOSE;
  static boolean[] isused = new boolean[19];
  static int[] gucard = new int[9];
  static int[] incard = new int[9];

  static void play(int depth) {
    if (depth == 9) {
      int guscore = 0, inscore = 0;
      for (int cardIndex = 0; cardIndex < 9; ++cardIndex) { // 9장의 카드를 비교하며 둘의 점수를 구해준다
        if (gucard[cardIndex] > incard[cardIndex]) guscore += gucard[cardIndex] + incard[cardIndex];
        else inscore += gucard[cardIndex] + incard[cardIndex];
      }
      if (guscore > inscore) ++WIN; // 이기면 WIN을
      else if (guscore < inscore) ++LOSE; // 지면 LOSE를 키워준다. 비기는 경우가 있기 때문에 else if로 비교해준다
      return;
    }

    for (int cardNum = 1; cardNum <= 18; ++cardNum) {
      if (isused[cardNum]) continue; // 이미 게임에 쓰인 카드라면 건너뛴다
      isused[cardNum] = true; // 카드를 쓸 거니 isused를 true로 바꿔주고

      incard[depth] = cardNum; // 인영의 카드 목록을 업데이트해준다
      play(depth + 1); // dfs를 한 칸 더 들어가준다
      
      isused[cardNum] = false; // 해당 카드를 쓴 회차를 벗어났으므로 다시 false로 바꿔준다
    }
  }

  static void init() {
    for (int i = 1; i <= 18; ++i) isused[i] = false;
    WIN = 0;
    LOSE = 0;
  }

  public static void main(String[] args) throws IOException {
    T = Integer.parseInt(br.readLine());

    for (int tc = 1; tc <= T; ++tc) {
      init();

      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int cardIndex = 0; cardIndex < 9; ++cardIndex) {
        gucard[cardIndex] = Integer.parseInt(st.nextToken()); // 규영의 카드 목록에 저장해주고
        isused[gucard[cardIndex]] = true; // 게임에 쓰인 카드이므로 isused를 업데이트해준다
      }

      // 실행
      play(0);

      // 결과 저장
      sb.append('#').append(tc).append(' ').append(WIN).append(' ').append(LOSE).append('\n');
    }

    // 최종 출력
    System.out.print(sb);
  }
}
