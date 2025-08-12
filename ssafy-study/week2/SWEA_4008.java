import java.io.*;
import java.util.*;

public class SWEA_4008 {
  
  static int T, N;
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringBuilder sb = new StringBuilder();
  static int[] calcSigns =  new int[4];
  static int[] calcNums = new int[15];

  static void calc() {
    int calcIdx = 0;
    int oth = calcNums[0];
    for (int i = 1; i < N; ++i) {
      
    }
  }

  public static void main(String[] args) throws IOException {
    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      N = Integer.parseInt(br.readLine());

      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int i = 0; i < 4; ++i) calcSigns[i] = Integer.parseInt(st.nextToken());
      st = new StringTokenizer(br.readLine());
      for (int i = 0; i < N; ++i) calcNums[i] = Integer.parseInt(st.nextToken());
    }
  }
}
