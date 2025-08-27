import java.io.*;
import java.util.*;

public class SWEA_3124_2 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, V, E;
  static ArrayList<int[]>[] adj = new ArrayList[100_002]; // {cost, to}
  static boolean[] chk = new boolean[100_002];

  static long run() {
    PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(x -> x[0])); // element: {cost, to}
    // 정점 하나 넣고 시작
    chk[1] = true;
    for (int[] nxt : adj[1]) pq.add(nxt);

    // 프림 알고리즘
    int cnt = 0;
    long sum = 0;
    while (cnt < V - 1) {
      int[] cur = pq.poll(); // 루트 하나 빼기. 최소거리.
      int v = cur[1];
      if (chk[v]) continue;

      chk[v] = true;
      sum += cur[0];
      ++cnt;
      for (int[] nxt : adj[v]) {
        if (!chk[nxt[1]]) pq.add(nxt);
      }
    }
    return sum;
  }

  static void init() {
    Arrays.fill(chk, false);
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());

    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      V = Integer.parseInt(st.nextToken());
      E = Integer.parseInt(st.nextToken());

      // 초기화
      init();

      for (int i = 0; i < E; ++i) {
        st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        adj[a].add(new int[]{c, b});
        adj[b].add(new int[]{c, a});
      }

      // 실행 & 출력
      sb.append('#').append(tc).append(' ').append(run()).append('\n');
    }
    System.out.print(sb);
  }
}
