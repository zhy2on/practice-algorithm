import java.io.*;
import java.util.*;

public class BOJ_11725_dfs {
  
  static List<Integer>[] adj;
  static int[] p;

  static void dfs(int cur) {
    for (int nxt : adj[cur]) {
      if (nxt == p[cur]) continue;
      p[nxt] = cur;
      dfs(nxt);
    }
  }

  static void init(int N) {
    adj = new ArrayList[N + 1];
    for (int i = 1; i < N + 1; ++i) adj[i] = new ArrayList<>();
    p = new int[N + 1];
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());
    init(N);

    // 입력
    for (int i = 0; i < N - 1; ++i) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());

      adj[u].add(v);
      adj[v].add(u);
    }

    // dfs
    dfs(1);

    // 출력
    StringBuilder sb = new StringBuilder();
    for (int i = 2; i <= N; ++i) {
      sb.append(p[i]).append('\n');
    }

    System.out.print(sb);
  }
}
