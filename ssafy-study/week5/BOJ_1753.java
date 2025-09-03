import java.io.*;
import java.util.*;

public class BOJ_1753 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static final int DIST = 0, NODE = 1;
  static final int INF = (int) 1e9+10;
  static int V, E, K;
  static ArrayList<int[]>[] adj = new ArrayList[20_005];
  static int[] d = new int[20_005];

  static void run() {
    PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(x -> x[0])); // element: {dist, node}

    // 초기화
    Arrays.fill(d, 1, V + 1, INF);
    // 첫 정점 넣기
    pq.offer(new int[]{0, K});
    d[K] = 0;

    while (!pq.isEmpty()) {
      int[] cur = pq.poll(); // {dist, node}
      if(d[cur[NODE]] < cur[DIST]) continue;

      for (int[] nxt : adj[cur[NODE]]) {
        if (d[nxt[NODE]] <= d[cur[NODE]] + nxt[DIST]) continue;
        d[nxt[NODE]] = d[cur[NODE]] + nxt[DIST];

        pq.offer(new int[]{d[nxt[NODE]], nxt[NODE]});
      }
    }
  }

  static void init() {
    for (int i = 1; i <= V; ++i) adj[i] = new ArrayList<>();
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    V = Integer.parseInt(st.nextToken());
    E = Integer.parseInt(st.nextToken());

    K = Integer.parseInt(br.readLine());

    init();

    for (int i = 0; i < E; ++i) {
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      int cost = Integer.parseInt(st.nextToken());
      adj[u].add(new int[]{cost, v});
    }

    // 실행
    run();
    for (int i = 1; i <= V; ++i) sb.append(d[i] == INF ? "INF" : d[i]).append('\n');
    System.out.print(sb);
  }
}
