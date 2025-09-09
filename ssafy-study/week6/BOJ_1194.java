import java.io.*;
import java.util.*;

public class BOJ_1194 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int N, M;
  static char[][] board = new char[52][52];
  static int[][] dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  static int bfs(int sx, int sy) {
    int[][][] dist = new int[1 << 6][N][M];

    Queue<int[]> q = new ArrayDeque<>();
    // 큐에 {x, y, 이동 횟수, 현재 가진 키}를 저장
    q.offer(new int[]{sx, sy, 0, 0}); 
    dist[0][sx][sy] = 1; // 0은 방문 안한 상태, 1부터 시작

    while (!q.isEmpty()) {
      int[] current = q.poll();
      int x = current[0];
      int y = current[1];
      int count = current[2];
      int keyStatus = current[3];

      // 출구 '1'을 만나면 즉시 종료
      if (board[x][y] == '1') return count;

      for (int d = 0; d < 4; d++) {
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M || board[nx][ny] == '#') continue;

        char nextPos = board[nx][ny];

        // 1. 열쇠를 만났을 때
        if (nextPos >= 'a' && nextPos <= 'f') {
          int newKeyStatus = keyStatus | (1 << (nextPos - 'a'));
          if (dist[newKeyStatus][nx][ny] == 0) {
            dist[newKeyStatus][nx][ny] = count + 1;
            q.offer(new int[]{nx, ny, count + 1, newKeyStatus});
          }
        } 
        // 2. 문을 만났을 때
        else if (nextPos >= 'A' && nextPos <= 'F') {
          // 해당 문에 대한 키가 있는지 확인
          if ((keyStatus & (1 << (nextPos - 'A'))) != 0) {
            if (dist[keyStatus][nx][ny] == 0) {
              dist[keyStatus][nx][ny] = count + 1;
              q.offer(new int[]{nx, ny, count + 1, keyStatus});
            }
          }
        }
        // 3. 빈 칸('.') 또는 출구('1')를 만났을 때
        else {
          if (dist[keyStatus][nx][ny] == 0) {
            dist[keyStatus][nx][ny] = count + 1;
            q.offer(new int[]{nx, ny, count + 1, keyStatus});
          }
        }
      }
    }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    return -1; // 탈출 불가능
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    int sx = -1, sy = -1;
    for (int i = 0; i < N; ++i) {
      board[i] = br.readLine().toCharArray();
      for (int j = 0; j < M; ++j) {
        if (board[i][j] == '0') {
          sx = i; sy = j;
        }
      }
    }

    System.out.print(bfs(sx, sy));
  }
}
