import java.io.*;
import java.util.*;

public class SWEA_1238 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static ArrayList<Integer>[] adj = new ArrayList[101]; // 간선 배열 1-based
  static boolean[] vis = new boolean[101];
  static int N, S; // 입력 개수, 시작 노드

  static int run() {
    int maxD = 0, ans = 0;
    Queue<int[]> q = new ArrayDeque<>();
    q.offer(new int[] {S, 0}); // start, dist
    vis[S] = true;

    while (!q.isEmpty()) {
      int[] cur = q.poll();
      for (int nxt : adj[cur[0]]) {
        if (vis[nxt]) continue;
        q.offer(new int[] {nxt, cur[1] + 1});
        vis[nxt] = true;
        if (cur[1] + 1 > maxD) {
          maxD = cur[1] + 1;
          ans = nxt;
        } else if (cur[1] + 1 == maxD) ans = Math.max(ans, nxt);
      }
    }
    return ans;
  }

  static void init() {
    for (int i = 1; i <= 100; ++i) {
      adj[i] = new ArrayList<Integer>();
      vis[i] = false;
    }
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    for (int tc = 1; tc <= 10; ++tc) {
      //초기화
      init();

      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      S = Integer.parseInt(st.nextToken());
      st = new StringTokenizer(br.readLine());
      for (int i = 0; i < N / 2; ++i) {
        int u = Integer.parseInt(st.nextToken());
        int v = Integer.parseInt(st.nextToken());
        adj[u].add(v);
      }

      // 실행
      sb.append('#').append(tc).append(' ').append(run()).append('\n');
    }
    System.out.print(sb);
  }
}
