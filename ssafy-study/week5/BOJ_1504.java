import java.io.*;
import java.util.*;

public class BOJ_1504 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static final int INF = (int) 1e9+10;
  static int N, E;
  static ArrayList<Edge>[] adj = new ArrayList[802];

  static class Edge implements Comparable<Edge> {
    int v, w;
    Edge(int v, int w) { this.v = v; this.w = w; }
    public int compareTo(Edge o) { return Integer.compare(this.w, o.w); }
  }

  static int dijkstra(int from, int to) {
    int[] d = new int[802];
    Arrays.fill(d, INF);

    PriorityQueue<Edge> pq = new PriorityQueue<>();
    pq.offer(new Edge(from, 0));
    d[from] = 0;
    while (!pq.isEmpty()) {
      Edge cur = pq.poll();
      if (d[cur.v] != cur.w) continue;
      if (cur.v == to) break;

      for (Edge nxt : adj[cur.v]) {
        if (d[nxt.v] <= d[cur.v] + nxt.w) continue;
        d[nxt.v] = d[cur.v] + nxt.w;
        pq.offer(new Edge(nxt.v, d[nxt.v]));
      }
    }
    return d[to];
  }

  static int run(int v1, int v2) {
    int a, b, c;
    // 1안) 1 -> v1 -> v2 -> N
    a = dijkstra(1, v1);
    b = dijkstra(v1, v2);
    c = dijkstra(v2, N);
    int dist1 = (a >= INF || b >= INF || c >= INF) ? INF : a + b + c;

    // 2안) 1 -> v2 -> v1 -> N
    a = dijkstra(1, v2);
    b = dijkstra(v2, v1);
    c = dijkstra(v1, N);
    int dist2 = (a >= INF || b >= INF || c >= INF) ? INF : a + b + c;
    
    int ans = Math.min(dist1, dist2);
    return ans >= INF ? -1 : ans;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    E = Integer.parseInt(st.nextToken());

    for (int i = 1; i <= N; ++i) adj[i] = new ArrayList<>();

    for (int i = 0; i < E; ++i) {
      st = new StringTokenizer(br.readLine());
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());
      int c = Integer.parseInt(st.nextToken());

      adj[a].add(new Edge(b, c));
      adj[b].add(new Edge(a, c));
    }

    st = new StringTokenizer(br.readLine());
    int v1 = Integer.parseInt(st.nextToken());
    int v2 = Integer.parseInt(st.nextToken());

    System.out.print(run(v1, v2));
  }
}
