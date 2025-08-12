import java.io.*;
import java.util.*;

public class BOJ_1759 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int L, C;
  static char[] alphabet = new char[15];
  static char[] password = new char[15];

  static int isAeiou(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : 0;
  }

  static void dfs(int st, int k, int aeiou) { // L개를 뽑아야 한다
    if (k == L) {
      if (aeiou < 1 || k - aeiou < 2) return;
      for (int i = 0; i < k; ++i) sb.append(password[i]);
      sb.append('\n');
      return;
    }
    for (int i = st; i < C; ++i) {
      password[k] = alphabet[i];
      dfs(i + 1, k + 1, aeiou + isAeiou(password[k]));
    }
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    L = Integer.parseInt(st.nextToken());
    C = Integer.parseInt(st.nextToken());

    alphabet = br.readLine().replace(" ", "").toCharArray();
    Arrays.sort(alphabet);
    dfs(0, 0, 0);
    System.out.print(sb);
  }
}
