import java.io.*;
import java.util.*;

public class SWEA_1251_2 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N;
  static double E;
  static long[][] node = new long[1005][2]; // 노드 좌표 저장
  static boolean[] chk = new boolean[1005]; // chk[i]: i번째 정점이 MST에 속해 있는가?

  static long w(int u, int v) {
    long d = (node[u][0] - node[v][0]) * (node[u][0] - node[v][0]);
    d += (node[u][1] - node[v][1]) * (node[u][1] - node[v][1]);
    return d;
  }

  static long run() {
    // 프림 알고리즘 element: {cost, to}
    PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(x -> x[0]));
    chk[0] = true; // 0번에서 시작

    // 0번 인접 간선 중 최소인 애 넣기
    for (int v = 1; v < N; ++v) {
      pq.add(new long[]{w(0, v), v}); // 루트가 최소가 되도록 유지됨
    }

    // pq 돌며 진행
    int cnt = 0; // 현재 선택된 간선의 수
    long sum = 0; // 최소거리 합
    while (cnt < N - 1) {
      long[] cur = pq.poll(); // cost, to
      int v = (int) cur[1];
      if (chk[v]) continue; // 이미 MST에 속해있으면 continue

      chk[v] = true;
      sum += cur[0];
      ++cnt;

      // v에서 뻗는 간선들 추가 (미방문만)
      for (int u = 0; u < N; ++u) {
        if (!chk[u]) pq.add(new long[]{w(v, u), u});
      }
    }

    return Math.round(sum * E); // 세율 적용 후 반올림
  }

  static void init() {
    Arrays.fill(chk, false);
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 초기화
      init();

      // 입력
      N = Integer.parseInt(br.readLine());

      // x좌표
      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int i = 0; i < N; ++i) node[i][0] = Integer.parseInt(st.nextToken());

      // y좌표
      st = new StringTokenizer(br.readLine());
      for (int i = 0; i < N; ++i) node[i][1] = Integer.parseInt(st.nextToken());

      // 세율
      E = Double.parseDouble(br.readLine());

      // 실행 & 출력
      sb.append('#').append(tc).append(' ').append(run()).append('\n');
    }
    System.out.print(sb);
  }
}
