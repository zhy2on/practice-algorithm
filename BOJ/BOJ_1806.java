import java.io.*;
import java.util.*;

public class BOJ_1806 {
    
    static BufferedReader br;
    static int N, S;
    static int[] arr = new int[100002];

    public static void main(String args[]) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i) arr[i] = Integer.parseInt(st.nextToken());

        int left = 0;
        int sum = 0;
        int len = Integer.MAX_VALUE;
        for (int right = 0; right < N; ++right) {
            sum += arr[right];

            while (sum >= S) {
                len = Math.min(len, right - left + 1);
                sum -= arr[left++];
            }
        }

        if (len == Integer.MAX_VALUE) System.out.print(0);
        else System.out.print(len);    
    }
}
