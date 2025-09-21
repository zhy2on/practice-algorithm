import java.io.*;
import java.util.*;

public class BOJ_14584 {

  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static int N;
  static char[] cyper = new char[102];
  static String[] word = new String[22];
  
  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    cyper = br.readLine().toCharArray();
    N = Integer.parseInt(br.readLine());

    for (int i = 0; i < N; ++i) word[i] = br.readLine();

    while (true) {
      for (int i = 0; i < cyper.length; ++i) {
        if (cyper[i] >= 'a' && cyper[i] <= 'z') cyper[i] = (char)('a' + (cyper[i] - 'a' + 1) % 26);
        else cyper[i] = (char)('A' + (cyper[i] - 'A' + 1) % 26);
      }
      
      String cy = new String(cyper);
      
      for (int i = 0; i < N; ++i) {
        if (cy.contains(word[i])) {
          System.out.println(cy);
          return;
        }
      }
    }
  }
}
