import java.io.*;
import java.util.*;

public class BOJ_17472 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int N, M, I = 0;
  static int[][] board = new int[12][12];
  static int[][] dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  static ArrayList<Edge>[] adj = new ArrayList[8];

  static class Edge implements Comparable<Edge> {
    int x, y, w; // v 말고 보드 위치 x, y 저장하게 했음. 이래야 나중에 board[x][y]로 섬 번호 업데이트 돼도 알아챌 수 있으니까
    public Edge(int x, int y, int w) { this.x = x; this.y = y; this.w = w; }
    public int compareTo(Edge o) { return Integer.compare(this.w, o.w); }
  }

  static void addEdge(int sx, int sy, int d, int islandN) { // 외곽에서 다른 섬까지의 거리 구해서 adj 추가하기
    int step = 1;
    while (true) { // 외곽 위치부터 나가려던 방향으로 쭉 갔을 때 다른 섬 만나면 그게 다리 길이
      int nx = sx + step * dir[d][0], ny = sy + step * dir[d][1];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) break; // 이때는 맵 나가면 멈춰야 됨

      if (board[nx][ny] != 0) {
        if (step > 1) { // 길이가 1보다 커야 추가
          adj[islandN].add(new Edge(nx, ny, step));
        }
        break; // 찾았으면 탈출
      }
      ++step;
    }
  }

  static void bfs(int sx, int sy) { // 섬 번호 채우기 + 간선 추가하기
    ++I; // 섬 번호 업데이트
    Queue<int[]> q = new ArrayDeque<>();
    q.offer(new int[]{sx, sy});
    board[sx][sy] = I;

    while (!q.isEmpty()) {
      int[] cur = q.poll();
      
      for (int d = 0; d < 4; ++d) {
        int nx = cur[0] + dir[d][0], ny = cur[1] + dir[d][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (board[nx][ny] == 0) { // 섬에서 바다로 나가버린 순간 다리길이 구해서 edge 추가하고 continue
          addEdge(nx, ny, d, I);
          continue;
        }
        if (board[nx][ny] >= 0) continue; // 이미 방문한 곳이면 continue

        board[nx][ny] = I; // 섬 번호로 업데이트
        q.offer(new int[]{nx, ny});
      }
    }
  }

  static void unite() { // bfs로 섬 번호 정하기 + 번호 정하면서 간선 추가하기
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (board[i][j] == -1) bfs(i, j);
      }
    }
  }

  static int prim() {
    boolean[] chk = new boolean[I + 1];
    PriorityQueue<Edge> pq = new PriorityQueue<>();
    int picked = 1;
    chk[1] = true;
    for (Edge nxt : adj[1]) { pq.add(nxt); }

    int dist = 0;
    while (!pq.isEmpty() && picked < I) {
      Edge cur = pq.poll();
      int v = board[cur.x][cur.y];
      if (chk[v]) continue; // 이미 MST에 속해있다면

      chk[v] = true;
      ++picked;
      dist += cur.w;

      for (Edge nxt : adj[v]) { pq.add(nxt); }
    }
    return (picked == I) ? dist : -1;
  }

  static int run() {
    for (int i = 1; i <= 6; ++i) adj[i] = new ArrayList<>(); // 최대개수 6밖에 안 되니까 그냥 6까지 초기화

    unite(); // 섬 그룹 정하기 + 간선 추가하기
    return prim(); // 프림으로 MST 구하기
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    for (int i = 0; i < N; ++i) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < M; ++j) {
        board[i][j] = -Integer.parseInt(st.nextToken()); // 섬을 -1로 받아버리기
      }
    }

    System.out.print(run());
  }
}
