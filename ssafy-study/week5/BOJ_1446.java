import java.io.*;
import java.util.*;

public class BOJ_1446 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static final int INF = (int) 1e9+10;
  static int N, D;
  static ArrayList<Edge>[] adj = new ArrayList[10002]; // {cost, v}

  static class Edge implements Comparable<Edge> {
    int v, w;
    Edge(int v, int w) { this.v = v; this.w = w; }
    public int compareTo(Edge o) { return Integer.compare(this.w, o.w); }
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    D = Integer.parseInt(st.nextToken());

    for (int i = 0; i <= D; ++i) adj[i] = new ArrayList<>(); // 할당은 D까지 해줘야함. 그래야 안 터짐

    for (int i = 0; i < N; ++i) {
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      int w = Integer.parseInt(st.nextToken());
      if (v <= D) adj[u].add(new Edge(v, w)); // 역주행 못함. v가 D까지밖에 유효하지 않음
    }

    // 연결안 된 간선 모두 연결하기
    for (int i = 0; i < D; ++i) {
      adj[i].add(new Edge(i + 1, 1)); // {dist, v}
    }

    // dijkstra
    int[] d = new int[D + 1];
    Arrays.fill(d, INF);
    PriorityQueue<Edge> pq = new PriorityQueue<>();
    pq.offer(new Edge(0, 0)); // {cost, v}
    d[0] = 0;

    while (!pq.isEmpty()) {
      Edge cur = pq.poll();
      if (d[cur.v] != cur.w) continue;

      for (Edge nxt : adj[cur.v]) {
        if (d[nxt.v] <= d[cur.v] + nxt.w) continue;
        d[nxt.v] = d[cur.v] + nxt.w;
        pq.offer(new Edge(nxt.v, d[nxt.v]));
      }
    }

    // 출력
    System.out.print(d[D]);
  }
}
