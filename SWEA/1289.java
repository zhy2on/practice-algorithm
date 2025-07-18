import java.io.*;
class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		 
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; ++t) {
			int cnt = 0;
			char[] str = br.readLine().toCharArray();
			if (str[0] == '1') ++cnt;
			for (int i = 1; i < str.length; ++i) {
				if (str[i] != str[i-1]) ++cnt;
			}
			System.out.println("#" + t + " " + cnt);
		}
	}
}
