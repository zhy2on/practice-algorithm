import java.io.*;
import java.util.*;

/*
 * 페르마 소정리를 이용한다.
 * nCr 은 n! / (r! (n-r)!) 이다.
 * 이 문제에선 (n! / (r! (n-r)!)) % 1234567891을 구해야 한다.
 * 모듈러 연산이 필요하다. 그런데 모듈러 연산에서 나눗셈은 직접적으로 할 수 없다. (곱셈이나 덧셈만 괜찮다)
 * 그렇기에 페르마 소정리를 이용하여 "역원"을 구하고 이를 "곱해야"한다.
 * 페르마 소정리는 다음과 같다.
 * 정수 a와 소수 p가 있을 때, a가 p의 배수가 아니라면 a^(p-1) mod p 는 1이다.
 * 이를 응용하면 a^(p-2)를 통해 a^(-1)을 구할 수 있다. : a^(p-1) mod p = 1 양변을 a로 나누면a^(p-2) mod p = a^(-1)
 * 
 * n! / (r! (n-r)!)은 n! * (r! (n-r)!)^(-1)
 * 1234567891은 소수(prime)
 * (r! (n-r)!)^(-1) mod p를 (r! (n-r)!)^(p-2)를 가지고 구한다.
 * 
 * 전처리로 fact[i] = i! mod p, invFact[i] = (i!)^(-1) mod p 를 만들어두면
 * nCr = fact[n] * invFact[r] % p * invFact[n-r] % p 로 O(1)에 구할 수 있다.
 */

public class SWEA_5607 {
  
  static BufferedReader br;
  static StringBuilder sb = new StringBuilder();
  static final long P = 1234567891L;
  static final int MAX = 1_000_000;    // N의 최댓값
  static long[] fact = new long[MAX + 1];
  static long[] invFact = new long[MAX + 1];
  static int T, N, R;

  // 거듭제곱 빠르게 (binary exponentiation)
  static long modPow(long a, long e) {
    long res = 1;
    a %= P;
    while (e > 0) {
      if ((e & 1) == 1) res = (res * a) % P;
      a = (a * a) % P;
      e >>= 1;
    }
    return res;
  }

  static void precompute() {
    fact[0] = 1;
    // 1. fact[] : 0!부터 MAX!까지 팩토리얼부터 구하기
    for (int i = 1; i <= MAX; ++i) {
      fact[i] = (fact[i - 1] * i) % P;
    }
    // 2. invFact[MAX] : fact[MAX]^(MOD-2) % P (페르마 소정리로 역원 구하기)
    invFact[MAX] = modPow(fact[MAX], P - 2); 
    // 3. i! = (i + 1)!/(i + 1) 이용. invFact[i] : invFact[i+1] * (i+1) % P
    for (int i = MAX - 1; i >= 0; --i) {
      invFact[i] = (invFact[i + 1] * (i + 1)) % P;
    }
  }

  // nCr = fact[n] * invFact[r] % P * invFact[n-r] % P
  static long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % P) * invFact[n - r]) % P;
  }

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));

    precompute();

    T = Integer.parseInt(br.readLine());
    for (int tc = 1; tc <= T; ++tc) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      R = Integer.parseInt(st.nextToken());
      sb.append('#').append(tc).append(' ').append(nCr(N, R)).append('\n');
    }
    System.out.print(sb);
  }
}
