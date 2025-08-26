import java.io.*;
import java.util.*;

public class BOJ_1005 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T, N, K, W;
  static int[] D = new int[1002];
  static List<Integer>[] adj = new ArrayList[1002];
  static int[] degree = new int[1002];
  static int[] dp = new int[1002];

  static int run() {
    ArrayDeque<Integer> q = new ArrayDeque<>();

    for (int i = 1; i <= N; ++i) { // 진입차수 0인 애들 넣기
      if (degree[i] == 0) {
        dp[i] = D[i];
        q.add(i);
      }
    }

    while (!q.isEmpty()) {
      int u = q.poll();
      if (u == W) return dp[W];
      for (int v : adj[u]) {
        dp[v] = Math.max(dp[v], dp[u] + D[v]);
        if (--degree[v] == 0) q.push(v);
      }
    }
    return -1;
  }

  static void init() {
    for (int i = 1; i <= N; ++i) adj[i] = new ArrayList<>();
    for (int i = 1; i <= N; ++i) degree[i] = 0;
    for (int i = 1; i <= N; ++i) dp[i] = 0;
  }
  
  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    
    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      K = Integer.parseInt(st.nextToken());

      init();

      st = new StringTokenizer(br.readLine());
      for (int i = 1; i <= N; ++i) D[i] = Integer.parseInt(st.nextToken());

      for (int i = 0; i < K; ++i) {
        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        adj[x].add(y);
        ++degree[y];
      }

      W = Integer.parseInt(br.readLine());
      System.out.println(run());
    }
  }
}
