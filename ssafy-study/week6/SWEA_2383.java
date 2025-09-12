import java.io.*;
import java.util.*;

public class SWEA_2383 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, P, S;
  static int[][] board = new int[12][12];
  static int[][] people = new int[12][2];
  static int[][] stair = new int[2][2];

  static int simulation(ArrayList<Integer> wait, int K) {
    if (wait.isEmpty()) return 0;

    Collections.sort(wait); // 도착시간순 정렬
    ArrayDeque<Integer> dq = new ArrayDeque<>(); // 계단에 올라갈 사람들

    for (int i = 0; i < wait.size(); ++i) {
      int t = wait.get(i);

      // 내가 도착했을 때 pq에서 이미 계단을 내려간 사람들을 pop 해줌
      while (!dq.isEmpty() && dq.peekFirst() + K <= t) dq.pollFirst();

      // 3명 꽉 차 있으면 한 명 보내줌
      if (dq.size() == 3) t = dq.pollFirst() + K;

      // 계단에 사람 보내기
      dq.addLast(t);
    }

    // 마지막 계단에 있는 사람 + 계단 길이가 답임
    return dq.peekLast() + K;
  }

  static int run() {
    // 계단 정하기
    int ans = Integer.MAX_VALUE;
    for (int mask = 0; mask < (1 << P); ++mask) {
      // 계단 대기열
      ArrayList<Integer>[] wait = new ArrayList[2];
      for (int i = 0; i < 2; ++i) wait[i] = new ArrayList<>();

      // 사람들에게 계단 분배
      for (int bit = 0; bit < P; ++bit) {
        int idx = (mask >> bit) & 1;
        int t = Math.abs(stair[idx][0] - people[bit][0]) + Math.abs(stair[idx][1] - people[bit][1]);
        wait[idx].add(t + 1); // 도착 1초 뒤부터 내려갈 수 있음. 그래서 t + 1로 넣기
      }

      // 최소 시간 구하기
      int t1 = simulation(wait[0], board[stair[0][0]][stair[0][1]]);
      int t2 = simulation(wait[1], board[stair[1][0]][stair[1][1]]);
      ans = Math.min(ans, Math.max(t1, t2));
    }
    return ans;
  }

  static void init() {
    P = 0; S = 0;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    br = new BufferedReader(new FileReader("ssafy-study/week6/sample_input.txt"));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 초기화
      init();

      // 입력
      N = Integer.parseInt(br.readLine());

      for (int i = 0; i < N; ++i) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int j = 0; j < N; ++j) {
          board[i][j] = Integer.parseInt(st.nextToken());
          if (board[i][j] == 0) continue;
          if (board[i][j] == 1) {
            people[P][0] = i;
            people[P++][1] = j;
          } else {
            stair[S][0] = i;
            stair[S++][1] = j;
          }
        }
      }

      // 실행
      sb.append('#').append(tc).append(' ').append(run()).append('\n');
    }
    System.out.print(sb);
  }
}
