import java.io.*;
import java.util.*;

public class SWEA_1767 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int[][] coreXY = new int[12][2]; // 가장 자리가 아닌 코어 좌표만 저장
  static int[] dx = new int[] {1, 0, -1, 0};
  static int[] dy = new int[] {0, -1, 0, 1};
  static int[][] board = new int[12][12];
  static int T, N, totalCnt, maxCore, ans;

  static int getLineLen(int x, int y, int dir) {
    int len = 0;
    while (true) {
      int nx = x + dx[dir], ny = y + dy[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= N) return len; // 마지막까지 도착했다면
      if (board[nx][ny] == 1) return -1; // 마지막에 도달 못한 거라면
      x = nx;
      y = ny;
      ++len;
    }
  }

  static void setLine(int x, int y, int dir, int len, int value) {
    for (int i = 0; i < len; ++i) {
      x += dx[dir];
      y += dy[dir];
      board[x][y] = value;
    }
  }

  static void dfs(int index, int connectedCnt, int totalLen) {
    // 가지치기. 남은 걸 모두 더해도 maxCore를 못 넘긴다면 그냥 return
    if (connectedCnt + (totalCnt - index) < maxCore) return;

    if (index == totalCnt) { // 기저 조건
      if (connectedCnt > maxCore) { // 최대 연결이라면
        maxCore = connectedCnt; // maxCore를 바꿔주고
        ans = totalLen; // 그냥 ans를 totalLen으로 업데이트
      } else if (connectedCnt == maxCore) { // 연결 수가 같다면
        ans = Math.min(ans, totalLen); // 더 짧은 길이가 ans
      }
      return;
    }

    // 전선 설치 안 하는 경우
    dfs(index + 1, connectedCnt, totalLen);

    // 전선 설치하는 경우
    for (int d = 0; d < 4; ++d) { // 4방향 전선 설치 시도
      int x = coreXY[index][0], y = coreXY[index][1];
      int len = getLineLen(x, y, d);
      if (len < 0) continue; // 전선 설치할 수 없으면 continue

      setLine(x, y, d, len, 1); // 전선 설치
      dfs(index + 1, connectedCnt + 1, totalLen + len); // 설치하고 들어감
      setLine(x, y, d, len, 0); // 다시 복구
    }
  }

  static void init() {
    totalCnt = 0;
    maxCore = 0;
    ans = Integer.MAX_VALUE;
  }

  static void print() {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) System.out.print(board[i][j] + " ");
      System.out.println();
    }
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 초기화
      init();

      // 입력
      N = Integer.parseInt(br.readLine());
      for (int i = 0; i < N; ++i) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int j = 0; j < N; ++j) {
          board[i][j] = st.nextToken().charAt(0) - '0';
          if (board[i][j] == 1) {
            if (i == N - 1 || j == N - 1) continue; // 가장자리라면 넣을 필요 없다
            coreXY[totalCnt++] = new int[] {i, j};
          }
        }
      }

      // 실행
      dfs(0, 0, 0);

      // 출력
      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }
    System.out.print(sb);
  }
}
