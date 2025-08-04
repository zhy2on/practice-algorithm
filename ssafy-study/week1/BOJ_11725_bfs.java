import java.io.*;
import java.util.*;

public class BOJ_11725_bfs {

  static List<Integer>[] adj;
  static int[] p;
  static int N;

  static void bfs() {
    Queue<Integer> q = new LinkedList<>();
    q.add(1);
  
    while (!q.isEmpty()) {
      int cur = q.poll();
      for (int nxt : adj[cur]) {
        if (p[nxt] != 0) continue;
        q.add(nxt);
        p[nxt] = cur;
      }
    }
  }

  static void init() {
    adj = new ArrayList[N + 1];
    for (int i = 1; i < N + 1; ++i) adj[i] = new ArrayList<>();
    p = new int[N + 1];
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    // 입력
    N = Integer.parseInt(br.readLine());
    init();

    for (int i = 0; i < N - 1; ++i) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      adj[u].add(v);
      adj[v].add(u);
    }

    // bfs
    bfs();

    // 출력
    StringBuilder sb = new StringBuilder();
    for (int i = 2; i <= N; ++i) sb.append(p[i]).append('\n');
    System.out.print(sb);
  }
}
