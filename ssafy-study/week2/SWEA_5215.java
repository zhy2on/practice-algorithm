import java.io.*;
import java.util.*;

public class SWEA_5215 {

  static final int SCORE = 0, CALO = 1;
  static int T, N, L, ans;
  static int[][] burger = new int[20][];
  static int[] selected = new int[20]; // 조합을 위한 0, 1로 채워지는 permutation array
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();

  static void swap(int i, int j) {
    int tmp = selected[i]; selected[i] = selected[j]; selected[j] = tmp;
  }

  static void reverse(int l, int r) {
    while (l < r) swap(l++, r--);
  }

  static boolean nextPermutation() {
    // pivot 찾기. 뒤에서부터 시작. 내림차순이 깨지는 순간
    int pivot = N - 2;
    while (pivot >= 0 && selected[pivot] >= selected[pivot + 1]) --pivot;
    if (pivot == -1) return false;

    // pivot보다 살짝 큰 값 찾기
    int swapi = N - 1;
    while (selected[pivot] >= selected[swapi]) --swapi;

    // swap
    swap(pivot, swapi);

    // reverse
    reverse(pivot + 1, N - 1);
    return true;
  }

  static void updateAns() {
    int scoreSum = 0, caloSum = 0;
    for (int i = 0; i < N; ++i) {
      if (selected[i] == 0) continue;
      scoreSum += burger[i][SCORE];
      caloSum += burger[i][CALO];
      if (caloSum > L) return;
    }
    ans = Math.max(scoreSum, ans);
  }

  static void init() {
    ans = 0;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      // 입력
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      L = Integer.parseInt(st.nextToken());

      for (int i = 0; i < N; ++i) {
        st = new StringTokenizer(br.readLine());
        burger[i] = new int[] {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
      }

      // 초기화
      init();

      // 실행
      for (int k = 1; k <= N; ++k) {
        // 처음엔 오름차순 정렬된 상태로 시작. N - k만큼 0으로 채우고 k개만큼 1로 채운다.
        for (int i = 0; i < N; ++i) selected[i] = i < N - k ? 0 : 1;
        // next permutation으로 선택된 햄버거 조합을 구하고 ans를 업데이트한다.
        do {
          updateAns();
        } while (nextPermutation());
      }

      sb.append('#').append(tc).append(' ').append(ans).append('\n');
    }
    System.out.print(sb);
  }
}
