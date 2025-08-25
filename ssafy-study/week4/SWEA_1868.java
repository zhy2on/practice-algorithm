import java.io.*;
import java.util.*;

public class SWEA_1868 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static char[][] board = new char[302][302];
  static int T, N;

  static void bfs(int sx, int sy) { // board[i][j] == '0'일 때 한꺼번에 방문처리하기 위한 함수
    ArrayDeque<int[]> q = new ArrayDeque<>();
    q.push(new int[]{sx, sy});
    board[sx][sy] = '-'; // 방문

    while (!q.isEmpty()) {
      int[] cur = q.pop();
      for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
          int nx = cur[0] + dx, ny = cur[1] + dy;
          if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // OOB check
          if (board[nx][ny] == '*' || board[nx][ny] == '-') continue; // 지뢰거나 방문했으면 continue
          
          if (board[nx][ny] == '0') q.push(new int[]{nx, ny}); // 0일 때만 큐에 넣음
          board[nx][ny] = '-'; // 방문 처리
        }
      }
    }
  }

  static int run() { // 필요한 클릭 수 구하기
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (board[i][j] == '0') { // 0이면
          bfs(i, j); // bfs로 한번에 처리해주고
          ++cnt; // cnt는 1 증가
        }
      }
    }

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (board[i][j] != '-' && board[i][j] != '*') ++cnt; // '0'칸 처리 했는데도 방문 안 된 애들은 하나씩 눌러줘야 함
      }
    }
    return cnt;
  }

  static void setNum() { // 근처에 있는 지뢰 개수로 board[i][j] 업데이트하기
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (board[i][j] == '*') continue;
        int cnt = 0;
        for (int dx = -1; dx <= 1; ++dx) {
          for (int dy = -1; dy <= 1; ++dy) {
            int nx = i + dx, ny = j + dy;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[nx][ny] == '*') ++cnt;
          }
        }
        board[i][j] = (char) ('0' + cnt);
      }
    }
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      N = Integer.parseInt(br.readLine());
      for (int i = 0; i < N; ++i) board[i] = br.readLine().toCharArray();

      setNum(); // 먼저 근처에 있는 지뢰 개수 채워주고
      sb.append('#').append(tc).append(' ').append(run()).append('\n'); // 실행
    }
    System.out.print(sb);
  }
}
