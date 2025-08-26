import java.io.*;
import java.util.*;

public class SWEA_1922 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int N, M;
  static int[] p = new int[1005];
  static int[][] edge = new int[100005][3];

  static int findp(int x) {
    if (p[x] < 0) return x;
    return p[x] = findp(p[x]); // 경로 압축
  }

  static boolean is_diff_group(int u, int v) {
    u = findp(u); v = findp(v);
    if (u == v) return false;

    if (p[u] > p[v]) { int t = p[u]; p[u] = p[v]; p[v] = t; } // union-by-size
    p[u] += p[v];
    p[v] = u;
    return true;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    Arrays.fill(p, -1); // p 초기화!! 중요

    N = Integer.parseInt(br.readLine());
    M = Integer.parseInt(br.readLine());
    for (int i = 0; i < M; ++i) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());
      int c = Integer.parseInt(st.nextToken());
      edge[i] = new int[] {a, b, c};
    }

    Arrays.sort(edge, 0, M, (x, y) -> x[2] - y[2]); // 범위 설정 중요!!

    int ans = 0, cnt = 0;
    for (int i = 0; i < M; ++i) {
      int[] cur = edge[i];
      if (!is_diff_group(cur[0], cur[1])) continue; // 같은 그룹이면 건너뜀
      ans += cur[2]; // 다른 그룹이었으면 cost를 정답에 더함
      ++cnt;
      if (cnt == N - 1) break; // 노드 - 1만큼 간선을 다 추가했으면 멈추기
    }
    System.out.print(ans);
  }
}
