# 정석
```cpp
struct NODE {
	struct NODE *prev, *next;
	int data;
};
```

# 야매버전
원소저장할 dat 배열, 이전 노드 다음 노드 가리킬 pre, nxt 배열 생성
```cpp
const int MX = 10000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

fill(pre, pre+MX, -1);
fill(nxt, nxt+MX, -1);
```

## traverse
```cpp
void traverse() {
	int cur = nxt[0];
	while (cur != -1) {
		cout << dat[cur] << ' ';
		cur = nxt[cur];
	}
	cout << "\n\n";
}
```

## insert
```cpp
void insert(int addr, int num) {
	// 원소 삽입
	dat[unused] = num;
	// 삽입한 원소의 pre와 nxt 변경
	pre[unused] = addr;
	nxt[unused] = nxt[addr];
	// 삽입될 다음 노드의 pre 변경
	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
	// 삽입될 잉전 노드의 nxt 변경
	nxt[addr] = unused;
	unused++;
}
```

## erase
```cpp
void erase(int addr) {
	// 이전 원소의 nxt 변경
	nxt[pre[addr]] = nxt[addr];
	// 다음 원소의  pre 변경
	if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}
```