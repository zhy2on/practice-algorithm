https://galid1.tistory.com/507 👍👍

다이나믹 프로그래밍이란?
-> 큰 문제를 작은 문제로 쪼개어 푸는 것

이전 단계의 최적해를 가지고 현재 단계의 최적해를 구할 수 있을 때 dp로 풀면 됨.

dp는 dfs로도 풀 수 있음. 대신 그럼 시간초과가 나게 됨.

왜냐면 예를들어 i-1 단계의 해에 단순히 2만 더하면 i 단계의 해가 되는데, dfs(완전 탐색)로 하면 매번 0, 1, ... i 단계까지의 계산을 하게 되는 거임.

그래서 메모이제이션이 필요함. 이전 회차의 결과값들을 저장하고 이를 활용함.

![](https://velog.velcdn.com/images/zhy2on/post/932fe12d-73ca-4f81-9f67-01739587606d/image.png)


## 2579
https://kwanghyuk.tistory.com/4 설명 👍👍

3번 연속해서 밟을 수 없다는 것에 주의.

그래서 경우의 수는
n-2칸까지의 최댓값 + 현재 칸
n-3칸까지의 최댓값 + n-1 칸 + 현재 칸

```cpp
int dp[301], stair[301];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> stair[i];
	}
	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < n; ++i) {
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}
	cout << dp[n - 1];
}
```

## 1149

dp[i][3]만 필요하다!
dp[i][0]은 현재 칠할 색이 R인 경우 이전에 G, B를 칠했을 때의 dp값 중 min값을 골라 더하고
dp[i][1]은 현재 칠할 색이 G인 경우 이전에 R, B를 칠했을 때의 dp값 중 min값을 골라 더하고...

이런 식으로 풀면 됨.

보면 dfs랑 다른 게 dfs는 모든 경우의 수를 파악해야 한다면
dp는 이전에 계산한 최적해를 가지고 현재 단계의 최적해를 구할 수 있음.(=메모이제이션)

```cpp
int dp[1001][3];
int color[1001][3];

int main(void) {
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> color[i][j];
		}
	}

	for (int i = 0; i < 3; ++i) {
		dp[0][i] = color[0][i];
	}

	for (int i = 1; i < n; ++i) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
	}

	cout << *min_element(dp[n - 1], dp[n - 1] + 3);
}
```

### 새로 안 거
min_element
여러 개 중 최솟값 찾을 때 유용. <algorithm\> 헤더에 있음.

## 11726
휴... 바로 안 보인다
잘 보면 이전 값을 활용할 수 있는 게 보임.
(dp[n-1]: 끝을 | 로 채우는 경우) + (dp[n-2]: 끝을 = 로 채우는 경우)

그래서 dp[n] = dp[n-1] + dp[n-2]

```cpp
#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	dp[0] = 1;
	dp[1] = 2;

	for (int i = 2; i < n; ++i) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
	}

	cout << dp[n - 1];
}
```

계산값의 overflow를 피하기 위해 문제에서 10007로 나눈 나머지 값을 사용하도록 했음. modulo 연산은 분배법칙 성립하기 때문에 최종값에 modulo 연산을 하는 게 아니라 중간 계산에 계속 모듈러 연산 사용해주면 됨

## 11659
간단한 문제. 구간합 구하기라 dp로 풀어야 하는 게 바로 보인다.

## 12852
ver 1
```cpp
#include <bits/stdc++.h>
using namespace std;

int dp[1000001], from[1000001], li[3];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	from[2] = 1;
	from[3] = 2;
	for (int i = 4; i <= n; ++i) {
		for (int i = 0; i < 3; ++i) li[i] = 100000;
		li[0] = dp[i - 1];
		if (i % 2 == 0) li[1] = dp[i / 2];
		if (i % 3 == 0) li[2] = dp[i / 3];

		int minn = li[0], minn_i = 0;
		for (int i = 1; i < 3; ++i) {
			if (li[i] < minn) {
				minn_i = i;
				minn = li[i];
			}
		}
		from[i] = minn_i;
		dp[i] = minn + 1;
	}

	cout << dp[n] << '\n';
	cout << n << ' ';
	while (n > 1) {
		if (from[n] == 0)
			n -= 1;
		else if (from[n] == 1)
			n /= 2;
		else if (from[n] == 2)
			n /= 3;
		cout << n << ' ';
	}
}
```

n으로 올 수 있는 경우는

n-1에서 +1로 오는 경우
n이 2로 나누어 떨어진다면 n/2에서 x2를 해서 오는 경우
n이 3으로 나누어 떨어진다면 n/3에서 x3을 해서 오는 경우이다.

처음에는 될 수 있는 경우에 따라 후보 배열 li[3]을 적절하게 채우고
min 값을 찾아 dp배열을 채웠다. 그리고 from 배열에는 이전에 +1을 해서 온 건지, x2를 해서 온 건지, x3을 해서 온 건지 0, 1, 2로 구분 해서 저장했었다.

ver 2
```cpp
#include <bits/stdc++.h>
using namespace std;

int dp[1000001], from[1000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	dp[1] = 0;
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1;
		from[i] = i - 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			from[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			from[i] = i / 3;
		}
	}

	cout << dp[n] << '\n';
	cout << n << ' ';
	while (n > 1) {
		cout << from[n] << ' ';
		n = from[n];
	}
}
```

ㅠㅠ 다시 보니까 코드가 너무 복잡했다.
바킹독님 풀이를 보니 li배열도 불필요 하고 from배열에 이전에 어떤 값에서 dp값이 선택된 건지 직접 넣어주면 훨씬 간단해진다는 것을 깨달았다.

비교할 값이 3개밖에 안 되니까 그냥 dp[i]에 dp[i-1] + 1로 초기값 주고
경우에 따라 dp[i/2] + 1, dp[i/3] + 1과 비교해가며 dp[i]를 없데이트 해주면 됐었다.

## 1003
```cpp
#include <bits/stdc++.h>
using namespace std;

int d[41][2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	d[0][0] = 1;
	d[1][1] = 1;
	for (int i = 2; i <= 40; ++i) {
		d[i][0] = d[i - 1][0] + d[i - 2][0];
		d[i][1] = d[i - 1][1] + d[i - 2][1];
	}

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		cout << d[n][0] << ' ' << d[n][1] << '\n';
	}
}
```
이제 진짜 피보나치는 알겠다!

## 1932

```cpp
#include <bits/stdc++.h>
using namespace std;

int a[502], b[502];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int k;
	cin >> k;
	a[1] = k;

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			cin >> k;
			b[j] = max(a[j - 1], a[j]) + k;
		}
		for (int j = 1; j <= i; ++j) {
			a[j] = b[j];
		}
	}
	cout << *max_element(a + 1, a + n + 1);
}
```
난 a, b 1차원 배열로 풀었는데 바킹독님은 2차원 배열로 놓고 그냥 삼각형 각 위치에서 입력받은 값, 최댓값을 따로 저장하셨다.

https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x10/solutions/1932.cpp#L15

괜히 복잡하게 생각하지 말고 직관적으로 풀 수 있는 방법이 문제 제한조건을 충분히 만족하면 직관적인 방법으로 풀기.

여기선 메모리 제한 128MB이니까 2차원 배열로 풀어도 괜찮았다.

![](https://velog.velcdn.com/images/zhy2on/post/a8556d4c-bd4c-4461-b457-683663825e01/image.png)

## 11727
ㅠ... 패턴이 아직도 안 익혀진다.
일단 n-1의 모든 경우의 수에 |를 추가하는 것
n-2의 모든 경우의 수에 ||, =, ㅁ을 추가하는 것이 dp[n].
그런데 dp[n-2]에 ||를 추가하는 것은 dp[n-1]에 |를 추가하는 것과 겹친다.
따라서 dp[n-1] + dp[n-2] * 2를 하면 된다.

```cpp
#include <bits/stdc++.h>
using namespace std;

int dp[1001];
int mod = 10007;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % mod;
	}
	cout << dp[n];
}
```

## 2193
```cpp
#include <iostream>
using namespace std;

long d[91][2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	d[1][1] = 1;

	int N;
	cin >> N;
	for (int i = 2; i <= N; ++i) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
	cout << d[N][0] + d[N][1];
}
```

int 말고 long으로 해야함!! 
전역변수는 0으로 초기화되니까 0값은 불필요하게 초기화 하지 말기

## 1912
```cpp
#include <bits/stdc++.h>
using namespace std;

long arr[100001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	long maxx = -1001;
	long tmp = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		tmp += arr[i];
		if (tmp > maxx) maxx = tmp;
		if (tmp < 0) tmp = 0;
	}
	cout << maxx;
}
```

![](https://velog.velcdn.com/images/zhy2on/post/6ead302d-dfb7-4108-a32d-9f63c2213057/image.jpeg)

tmp에 arr[i] 계속 더해가면서(연속합) maxx값 업데이트.
이때 더한 결과가 0보다 작아지게 되면 버려야 한다. 이전까지의 연속합 최댓값은 maxx에 저장되어 있으니까 ㄱㅊ다.


## 
```cpp
#include <bits/stdc++.h>
using namespace std;

int arr[1001], dp[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i]) dp[i] = max(dp[i], arr[i] + dp[j]);
		}
	}
	cout << *max_element(dp, dp + n);
}
```
ㅠ 안 풀려서 풀이 봤다.
n번째 인덱스가 증가 수열의 가장 끝 부분일 때의 값을 dp에 저장하면 된다.
이 경우 현재 인덱스보다 앞의 인덱스에서 나보다 작은 값들 중 dp의 최댓값에 나를 더해주면 된다.

## 11053
```cpp
#include <bits/stdc++.h>
using namespace std;

int arr[1001], dp[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j)
			if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j]);
		dp[i] += 1;
	}
	cout << *max_element(dp, dp + n);
}
```
앞에 거 풀었으니 쉽다! 이번엔 연속합이 아니라 길이기 때문에 dp에 길이를 저장해주면 된다.

## 9461
```cpp
#include <bits/stdc++.h>
using namespace std;

long p[101];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	fill(p + 1, p + 4, 1);
	fill(p + 4, p + 6, 2);
	p[6] = 3;
	p[7] = 4;
	p[8] = 5;
	for (int i = 9; i <= 100; ++i) {
		p[i] = p[i - 1] + p[i - 5];
	}
	for (int i = 0; i < t; ++i) {
		cin >> n;
		cout << p[n] << '\n';
	}
}
```
|![](https://velog.velcdn.com/images/zhy2on/post/6677ab70-239d-4f17-b1d4-9e8d6ebfb4c0/image.jpeg)|![](https://velog.velcdn.com/images/zhy2on/post/d0f8ec9f-0031-409f-b0ca-7d2d3a5b7040/image.jpeg)|
|----|----|

음 난 그림 다 그려보고 P(9)부터 점화식이 세워지길래 그렇게 했는데 바킹독님 풀이를 보니까 그냥 P(4)부터 P(n) = P(n-2) + P(n-3) 점화식을 찾아낼 수도 있었다..
근데 잘 이해 안 돼서 그냥 저 풀이 그대로 뒀다..

수열이다 점화식 찾아진다 앞에 거 활용할 수 있을 거 같다 -> dp 의심하기

우엑 더 이상 못하겠다
강의 더 듣고 다음에 dp 남은 문제 더 풀기

## 12865
https://www.acmicpc.net/problem/12865
와... 진짜 어렵다..

```cpp
#include <bits/stdc++.h>
using namespace std;

int dp[101][100001];
int item[101][2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> item[i][0] >> item[i][1];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			dp[i][j] = dp[i - 1][j];
			int w = item[i][0];
			if (w <= j) dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + item[i][1]);
		}
	}
	cout << dp[n][k];
}
```

이번 문제는 내가 가방에 들어갔을 때 가방의 최대 무게가 1부터 k일 때까지 최대 가치를 dp에 저장하면 됐다.

그래서 dp[101][100001]이 필요하다.
처음에 비슷하게 아이디어를 떠올렸어도 배열이 너무 큰 게 아닌가 했는데

![](https://velog.velcdn.com/images/zhy2on/post/10d038c3-3a40-42d3-922a-ff082e35ba91/image.png)

휴 난 바보다 문제 풀면서 시간 복잡도랑 메모리 크기 계산 빠릿빠릿하게 하는 연습 해야겠다.


다시 정리해보면 dp[i][1] ~ dp[i][k]는 내(item[i])가 가방에 들어갔을 때 최대 가치.

그래서 일단 dp[i][j] = dp[i-1][j]를 넣어준다. 왜냐면 j 무게 가방에서 내가 들어가지 않았을 때 최대 가치는 dp[i-1][j]에 일단 저장 되어 있는 상태니까.

그리고 내가 가방에 들어갈 수 있는 경우일 때 if (w <= j) 일 때 dp[i][j]를 갱신해준다.

이 때 내가 들어가는 경우 가치의 최댓값은 dp[i-1][j-w] + item[i][1]이다.
그리고 내가 들어가지 않았던 경우가 더 최댓값일 수 있으니 dp[i-1][j]랑 max로 비교해서 넣어준다.

여기서 dp[i-1][j-w]을 주의! dp[i][j-w]로 해서 틀렸었다. dp[i]~ 얘들은 "내가 들어간 경우" 값들이 저장 되어 있는 거임. 내 가치가 이미 더해져 있는 상태다.

여기에 또 내 가치를 더하면 중복이 발생한다.
