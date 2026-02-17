import java.io.*;
import java.util.*;

public class BOJ_1325_bfs {

    static BufferedReader br;
    static StringBuilder sb = new StringBuilder();
    static int N, M;
    static List<Integer>[] adj = new ArrayList[10002];
    static int[] cnt = new int[10002];

    static int bfs(int start) {
        int cnt = 0;
        boolean[] vis = new boolean[10002];
        ArrayDeque<Integer> q = new ArrayDeque<>();

        q.add(start);
        vis[start] = true;

        while (!q.isEmpty()) {
            int cur = q.poll();
            ++cnt;
            for (int nxt : adj[cur]) {
                if (vis[nxt]) continue;
                q.add(nxt);
                vis[nxt] = true;
            }
        }

        return cnt;
    }

    public static void main(String args[]) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= N; ++i) adj[i] = new ArrayList<>();

        for (int i = 0; i < M; ++i) {
            int A, B;
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            adj[B].add(A);
        }

        int[] cnt = new int[10002];
        int maxCnt = 0;
        for (int i = 1; i <= N; ++i) {
            cnt[i] = bfs(i);
            if (cnt[i] > maxCnt) {
                maxCnt = cnt[i];
                sb.setLength(0);
                sb.append(i).append(' ');
            } else if (cnt[i] == maxCnt) {
                sb.append(i).append(' ');
            }
        }

        System.out.print(sb);
    }
}
