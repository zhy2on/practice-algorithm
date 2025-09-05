#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
#define W first
#define V second

namespace {
	const int INF = 1e9 + 10;
	int N_;
	int p[5002]; // p[hotetID]: hotelID인 호텔의 부모노드
	int brand[5002]; // brand[hotelID]: hotelID인 호텔의 브랜드
	int root[52]; // root[brandID]: brandID인 그룹의 루트 노드
	vector<pair<int,int>> adj[5002]; // {weight, node}

	int findp(int x) {
		if (p[x] < 0) return x;
		return p[x] = findp(p[x]);
	}

	int unite(int u, int v) {
		int brandID = brand[u];
		u = findp(u); v = findp(v);
		if (u == v) return -1; // 같은 그룹이었으면 -1 반환

		if (p[u] > p[v]) swap(u, v);
		p[u] += p[v];
		p[v] = u;

		return u; // 새로운 그룹의 부모노드를 반환해주기
	}

	void update_brand(int u, int brandID) { // 루트가 u인 애들을 brandID로 업데이트
		for (int i = 0; i < N_; ++i) {
			int root = findp(i); // 루트노드가 u로 바뀐 애들은 다 brandID로 바꿔줘야함
			if (root == u) brand[i] = brandID;
		}
	}
}

void init(int N, int mBrands[]) // init OK
{
	N_ = N; // 전역변수로 저장해놓기

	fill(p, p + N + 1, -1); // p 초기화
	fill(root, root + 52, -1); // root 초기화
	fill(brand, brand + N + 1, -1); // brand 초기화
	for (int i = 0; i < N + 1; ++i) adj[i].clear();

	for (int i = 0; i < N; ++i) {
		brand[i] = mBrands[i];
		if (root[mBrands[i]] == -1) { // 브랜드에 해당하는 도시가 없었다면
			root[mBrands[i]] = i; // 나를 루트노드로 설정
		}
		else {
			unite(root[mBrands[i]], i); // 내 브랜드 그룹에 나를 합병
		}
	}
}

void connect(int mHotelA, int mHotelB, int mDistance)
{
	adj[mHotelA].push_back({ mDistance, mHotelB });
	adj[mHotelB].push_back({ mDistance, mHotelA });
}

int merge(int mHotelA, int mHotelB) // merge OK
{
	// hotelA의 브랜드아이디를 찾음
	int rootA = findp(mHotelA);
	int brandID = brand[mHotelA];

	// A와 B를 합치고
	int newRoot = unite(mHotelA, mHotelB);

	if (newRoot == -1) { // 안 합쳐졌으면, 이미 같은 그룹이었으면
		return -p[rootA]; // 그냥 원래 그룹 사이즈 반환해주면 됨
	}
	else { // 합쳐졌으면
		root[brandID] = newRoot; // brandID 그룹의 루트노드를 새로운 루트노드로 바꿔주고
		update_brand(newRoot, brandID); // 브랜드 업데이트. merge 호출횟수가 작으니까 여기서 해줘버리기
		return -p[newRoot]; // 새로운 그룹의 사이즈 반환
	}
}

int move(int mStart, int mBrandA, int mBrandB)
{ // 다익스트라로 시작점에서 최소거리 구해나가다가 mBrandA도 구하고 mBrandB도 구하면 그게 정답
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int d[5002];
	int minA = -1, minB = -1;

	fill(d, d + N_ + 1, INF); // d 초기화

	d[mStart] = 0;
	// 처음에 다 넣고 시작. 이러면 mStart가 리턴될 수가 없음
	for (auto nxt : adj[mStart]) {
		if (d[nxt.V] <= d[mStart] + nxt.W) continue;
		d[nxt.V] = d[mStart] + nxt.W;
		pq.push({ d[nxt.V], nxt.V });
	}

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.V] != cur.W) continue; // 최솟값이 업데이트 돼버렸던 거라면 continue

		if (minA == -1 && brand[cur.V] == mBrandA) minA = cur.V;
		if (minB == -1 && brand[cur.V] == mBrandB && minA != cur.V) minB = cur.V;

		if (minA !=-1 && minB !=-1) break;

		for (auto nxt : adj[cur.V]) {
			if (d[nxt.V] <= d[cur.V] + nxt.W) continue;
			d[nxt.V] = d[cur.V] + nxt.W;
			pq.push({ d[nxt.V], nxt.V });
		}
	}

	return d[minA] + d[minB];
}