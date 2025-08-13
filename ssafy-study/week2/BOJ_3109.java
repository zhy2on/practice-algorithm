import java.io.*;
import java.util.*;

public class BOJ_3109 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int R, C, ans;
  static char[][] board = new char[10000][500];

  static boolean dfs(int row, int col) {
    if (col == C - 1) {
      return true; // 끝까지 도달했다면 true를 리턴
    }

    for (int dr = -1; dr <= 1; ++dr) { // 오른쪽 위부터 탐색해야 함. 그리디 기법. 해당 위치에서 오른쪽 위부터 탐색해야 가장 최선임
      int nr = row + dr, nc = col + 1;
      if (nr < 0 || nr >= R || board[nr][nc] == 'x') continue; // 더 들어갈 수 없다면 continue
      board[nr][nc] = 'x'; // 방문 표시
      if (dfs(nr, nc)) return true; // 끝까지 도달했다면 다음 탐색을 더 할 필요 없음. return. 이때 true를 전파
      // 상태를 다시 복구시킬 필요가 없음. 이미 도달 실패한 경로라면 막다른 길. 다른 탐색에서 해당 경로를 재방문할 필요가 없음. (for 가지치기)
    }
    return false; // 도달하지 못했다면 false를 전파
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    // 입력
    StringTokenizer st = new StringTokenizer(br.readLine());
    R = Integer.parseInt(st.nextToken());
    C = Integer.parseInt(st.nextToken());
    for (int row = 0; row < R; ++row) {
      board[row] = br.readLine().toCharArray();
    }

    // 실행
    for (int row = 0; row < R; ++row) {
      if (dfs(row, 0)) ++ans; // 끝까지 도달했다면 ans를 업데이트
    }

    // 출력
    System.out.print(ans);
  }
}
