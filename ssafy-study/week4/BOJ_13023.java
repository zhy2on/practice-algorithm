import java.io.*;
import java.util.*;

public class BOJ_13023 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static StringTokenizer st;
  static int N, M, found;
  static ArrayList<Integer>[] adj = new ArrayList[2002];
  static boolean[] vis = new boolean[2002];

  static void dfs(int x, int k) {
    if (found == 1) return; // 찾았으면 바로 리턴
    if (k == 4) { // 4명의 연결된 친구 찾았으면
      found = 1; // found 업데이트 하고
      return; // 리턴
    }
    for (int nx : adj[x]) { // 인접 간선 dfs 들어가기
      if (vis[nx]) continue;
      vis[nx] = true;
      dfs(nx, k + 1);
      vis[nx] = false;
    }
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    for (int i = 0; i < N; ++i) adj[i] = new ArrayList<>();

    // 입력
    for (int i = 0; i < M; ++i) {
      st = new StringTokenizer(br.readLine());
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());
      adj[a].add(b);
      adj[b].add(a);
    }
    
    // 실행
    for (int i = 0; i < N && found == 0; ++i) {
      Arrays.fill(vis, false);
      vis[i] = true;
      dfs(i, 0);
    }

    // 출력
    System.out.print(found);
  }
}
