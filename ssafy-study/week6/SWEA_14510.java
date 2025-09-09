import java.io.*;
import java.util.*;

public class SWEA_14510 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int T;
  static int totalOnes, totalTwos;

  static boolean canSolve(long D) {
    if (D < 0) return false;
    
    long oddDays = (D + 1) / 2;
    long evenDays = D / 2;
    
    // +2 성장을 짝수 날에 최대한 할당한다.
    // 그래도 남는 +2 성장은 홀수 날 2개를 써서 해결해야 한다.
    long remainingTwos = Math.max(0, totalTwos - evenDays);
    
    // 필요한 총 홀수 날 = (원래 필요했던 +1 개수) + (남은 +2를 처리하기 위한 개수)
    long neededOddDays = totalOnes + remainingTwos * 2;
    
    return oddDays >= neededOddDays;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    T = Integer.parseInt(br.readLine());

    for (int tc = 1; tc <= T; ++tc) {
      int numTrees = Integer.parseInt(br.readLine());
      int[] trees = new int[numTrees];
      StringTokenizer st = new StringTokenizer(br.readLine());

      int maxHeight = 0;
      for (int i = 0; i < numTrees; ++i) {
        trees[i] = Integer.parseInt(st.nextToken());
        if (trees[i] > maxHeight) {
          maxHeight = trees[i];
        }
      }

      totalOnes = 0;
      totalTwos = 0;

      for (int i = 0; i < numTrees; ++i) {
        int diff = maxHeight - trees[i];
        if (diff > 0) {
          totalTwos += diff / 2;
          totalOnes += diff % 2;
        }
      }

      // 이분 탐색으로 최소 날짜(ans) 찾기
      long left = 0;
      // N*max_H 로 최대 차이가 100*120=12000, 2를 곱하면 대략 24000
      // 넉넉하게 큰 값으로 설정
      long right = 400000000; 
      long ans = right;

      while (left <= right) {
        long mid = left + (right - left) / 2;
        if (canSolve(mid)) {
          ans = mid;
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }

      sb.append("#").append(tc).append(" ").append(ans).append("\n");
    }
    System.out.print(sb);
  }
}