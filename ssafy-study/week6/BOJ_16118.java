import java.io.*;
import java.util.*;

public class BOJ_16118 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static final long INF = Long.MAX_VALUE / 4;
  static int N, M;
  static ArrayList<Edge>[] adj = new ArrayList[4002];
  static long[] dFox = new long[4002];
  static long[][] dWolf = new long[4002][2];

  static class Edge implements Comparable<Edge> {
    int v, s; // v, weight, state(늑대 도착 상태)
    long w;
    public Edge(int v, long w, int s) { this.v = v; this.w = w; this.s = s; }
    public int compareTo(Edge o) { return Long.compare(this.w, o.w); }
  }

  static void dijkstraFox() {
    Arrays.fill(dFox, INF);
    PriorityQueue<Edge> pq = new PriorityQueue<>();

    // 첫 정점 넣기
    pq.offer(new Edge(1, 0, -1)); // 여기선 s가 아무 의미 없음
    dFox[1] = 0;

    while (!pq.isEmpty()) {
      Edge cur = pq.poll();
      if (dFox[cur.v] != cur.w) continue;

      for (Edge nxt : adj[cur.v]) {
        long nd = cur.w + nxt.w;
        if (dFox[nxt.v] <= nd) continue;
        dFox[nxt.v] = nd;
        pq.offer(new Edge(nxt.v, dFox[nxt.v], -1));
      }
    }
  }

  static void dijkstraWolf() {
    for (int i = 1; i <= N; ++i) Arrays.fill(dWolf[i], INF);
    PriorityQueue<Edge> pq = new PriorityQueue<>();

    // 첫 정점 넣기
    pq.offer(new Edge(1, 0, 0)); // 시작: 다음 간선을 빠르게 달릴 차례
    dWolf[1][0] = 0;

    while (!pq.isEmpty()) {
      Edge cur = pq.poll();
      if (cur.w != dWolf[cur.v][cur.s]) continue;

      for (Edge nxt : adj[cur.v]) {
        if (cur.s == 0) {
          // 다음 간선을 빠르게: w / 2
          long nd = cur.w + nxt.w / 2;
          if (dWolf[nxt.v][1] <= nd) continue;
          dWolf[nxt.v][1] = nd;
          pq.offer(new Edge(nxt.v, nd, 1));
        } else {
          // 다음 간선을 느리게
          long nd = cur.w + nxt.w * 2;
          if (dWolf[nxt.v][0] <= nd) continue;
          dWolf[nxt.v][0] = nd;
          pq.offer(new Edge(nxt.v, nd, 0));
        }
      }
    }
  }

  static int run() {
    // 여우 d 먼저 구하기
    dijkstraFox();

    // 늑대 d 구하기
    dijkstraWolf();

    // 여우가 먼저 도착하는 정점 구하기
    int cnt = 0;
    for (int i = 2; i <= N; ++i) {
      if (dFox[i] < Math.min(dWolf[i][0], dWolf[i][1])) ++cnt;
    }
    return cnt;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    for (int i = 1; i <= N; ++i) adj[i] = new ArrayList<>();

    for (int i = 0; i < M; ++i) {
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      long w = Long.parseLong(st.nextToken()) * 2; // 분수 피하기 위해 2배로 저장
      adj[u].add(new Edge(v, w, 0));
      adj[v].add(new Edge(u, w, 0));
    }
    System.out.print(run());
  }
}
