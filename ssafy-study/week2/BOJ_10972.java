import java.io.*;
import java.util.*;

/*
 * 1. pivot 찾기 (내림차순이 깨지는 지점)
 *    - 뒤에서부터 탐색하여 arr[i-1] < arr[i]가 되는 최초의 위치(i-1)를 pivot으로 지정한다.
 *    - pivot 오른쪽은 이미 내림차순이므로, pivot 값을 더 크게 바꿔야 현재 순열보다 큰 순열을 만들 수 있다.
 *    - 이 위치만 바꾸면 앞부분은 그대로 두고, 뒤쪽을 조정해 '더 큰 순열 중 가장 작은 순열'을 만들 수 있다.
 *
 * 2. pivot보다 살짝 큰 값 찾기
 *    - pivot 오른쪽 구간에서 pivot보다 큰 값 중 가장 작은 값을 찾는다.
 *    - 오른쪽 구간은 내림차순이므로, 뒤에서부터 탐색하면 처음 만나는 pivot보다 큰 값이 곧 그 값이다.
 *
 * 3. swap
 *    - pivot과 찾은 값을 교환한다.
 *
 * 4. pivot 오른쪽 구간을 오름차순으로 만들기
 *    - pivot과 교환된 값 이후의 구간을 reverse하여 오름차순으로 만든다.
 *    - 이렇게 하면 해당 구간이 가능한 가장 작은 형태가 되어, 전체 순열이 사전순으로 '바로 다음'이 된다.
 */

public class BOJ_10972 {

  static int N;
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringBuilder sb = new StringBuilder();
  static int[] arr = new int[10001];

  static void swap(int[] a, int i, int j) {
    int t = a[i]; a[i] = a[j]; a[j] = t;
  }

  static void reverse(int[] a, int l, int r) {
    while (l < r) swap(a, l++, r--);
  }

  static void findNextPermutation() {

    // 1. pivot 찾기
    int pivot = N - 2;
    // arr[pivot] < arr[pivot + 1]인 구간에서 멈춰야 하기 때문에
    // while문은 arr[pivot] >= arr[pivot + 1]일 동안 돌아준다.
    while (pivot >= 0 && arr[pivot] >= arr[pivot + 1]) --pivot;
    if (pivot < 0) { // 이미 내림차순 => 다음 순열 없음
        System.out.print(-1);
        System.exit(0);
    }

    // 2. pivot이랑 swap할 애 찾기 (pivot보다 살짝 큰 값 찾기
    //                            == 오른쪽에서부터 찾을 때 처음으로 pivot 보다 큰 곳.
    //                            == pivot 오른쪽 구간은 내림차순 정렬 상태이기 때문에 처음으로 pivot 보다 큰 곳에서 멈추는 것이
    //                               곧 pivot 보다 살짝 더 큰 곳에서 멈춘 것이 된다.)
    int swapi = N - 1;
    while (arr[swapi] <= arr[pivot]) --swapi;

    // 3. swap 하기
    swap(arr, pivot, swapi);

    // 4. pivot 다음 구간을 reverse하기 (== 오름차순 정렬로 바꾸기. 바뀐 부분에서 제일 작은 수로 만들어야 하니까!
    //                                  reverse가 곧 오름차순으로 바꾸는 것이다. 원래 pivot 오른쪽은 내림차순 정렬 상태였기 때문에)
    reverse(arr, pivot + 1, N - 1);
  }

  public static void main(String[] args) throws IOException {

    N = Integer.parseInt(br.readLine().trim());
    StringTokenizer st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; ++i) arr[i] = Integer.parseInt(st.nextToken());
    
    findNextPermutation();
    for (int i = 0; i < N; ++i) sb.append(arr[i]).append(' ');
    System.out.println(sb);
  }
}
