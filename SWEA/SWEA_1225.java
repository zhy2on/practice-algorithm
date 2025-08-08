import java.io.*;
import java.util.*;

public class SWEA_1225 {

  static StringBuilder sb = new StringBuilder();
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static Deque<Integer> dq = new ArrayDeque<>();

  static void run() {
    while (true) {
      for (int i = 1; i <= 5; ++ i) {
        int n = dq.peekFirst() - i;
        if (n < 0) n = 0;
        dq.addLast(n);
        dq.removeFirst();
        if (n == 0) return;
      }
    }
  }

  static void init() {
    dq.clear();
  }
  
  public static void main(String[] args) throws IOException {
    
    for (int tc = 1; tc <= 10; ++tc) {

      // 초기화
      init();

      // 입력
      br.readLine(); // tc 입력 무시
      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int i = 0; i < 8; ++i) {
        dq.addLast(Integer.parseInt(st.nextToken()));
      }

      // 실행
      run();

      // 출력
      sb.append('#').append(tc).append(' ');
      for (int x : dq) {
        sb.append(x).append(' ');
      }
      sb.append('\n');
    }
    System.out.print(sb);
  }
}
