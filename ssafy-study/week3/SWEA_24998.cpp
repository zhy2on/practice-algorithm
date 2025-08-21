#include <vector>
#include <iostream>
using namespace std;

namespace {
  struct Node { int id; int r; int c; int q; }; // 캠프 = 노드
  int L_, N_;
  int B_;
  vector<Node> a; // camp 배열
  vector<int> p; // DSU. 음수배열. p[root] = -size(루트이면 -size를 가짐), p[x] = parent(루트 아니면 부모노드)
  vector<int> sum; // 광물합 배열
  vector<vector<vector<int>>> buckets; // 공간 압축을 위한 3차원 버킷 배열. buckets[br][bc]에 해당 그리드 안에 있는 베이스캠프 인덱스들 저장

  bool connectable(const Node &u, Node &v) {
    return (abs(u.r - v.r) + abs(u.c - v.c)) <= L_;
  }

  int findp(const int &x) { // 루트 노드 반환
    if (p[x] < 0) return x;
    return p[x] = findp(p[x]);  // union-find 최적화1. 경로 압축 - 자식노드들을 루트노드에 바로 연결시켜버림. 트리를 납작하게 만듦.
  }

  bool unite(const int &x, const int &y) { // x, y를 같은 그룹으로
    int rx = findp(x);
    int ry = findp(y);
    if (rx == ry) return false; // 이미 같은 그룹이면 리턴

    // union-find 최적화2. union-by-size. 노드 개수가 작은 트리를 큰 트리 밑으로 합침. 이러면 붙일 때부터 높이 O(log N) 이하 유지
    if (abs(p[rx]) < abs(p[ry])) swap(rx, ry); // size가 더 큰쪽 밑으로 합치게.
    p[rx] += p[ry]; // size 먼저 합침. p[roox] 사이즈가 p[rooty]만큼 늘어남.
    p[ry] = rx; // rooty 부모를 rootx로 변경.
    sum[rx] += sum[ry]; // 그룹합 업데이트
    return true;
  }
}

void init(int L, int N)
{
  L_ = L; N_ = N;
  B_ = (N_ + L_ - 1) / L_; // ceil(N / L)

  a.clear(); p.clear(); sum.clear();
  buckets.assign(B_, vector<vector<int>>(B_)); // 바로 buckets[br][bc]로 검사해줘야 하기 때문에 미리 할당을 해준다. 아니면 터짐.
}

int addBaseCamp(int mID, int mRow, int mCol, int mQuantity)
{ // 베이스캠프를 넣을 때 그룹 지정(union)을 해줘야함.
  int idx = a.size();

  Node n = { mID, mRow, mCol, mQuantity };
  a.push_back(n);
  p.push_back(-1);
  sum.push_back(n.q);

  int br = mRow / L_;
  int bc = mCol / L_;

  // 버킷에 넣기 전 union.
  // 공간 압축. 3x3 그리드에 있는 캠프들만 확인
  for (int dr = -1; dr <= 1; ++dr) {
    int nr = br + dr;
    if (nr < 0 || nr >= B_) continue;
    for (int dc = -1; dc <= 1; ++dc) {
      int nc = bc + dc;
      if (nc < 0 || nc >= B_) continue;

      for (int j : buckets[nr][nc]) {
        // union. 그룹 합치기
        if (connectable(a[idx], a[j])) unite(idx, j);
      }
    }
  }
  // 다 끝내면 버킷에 넣기
  buckets[br][bc].push_back(idx);
  return sum[findp(idx)]; // 루트 노드의 광물량 리턴해야 수집할 수 있는 광물의 최댓값.
}

int findBaseCampForDropping(int K)
{ // sum이 K 이상인 애 찾기. 이때 답이 여러개라면 q < r < c인 애를 선택.
  int best = -1;
  for (int i = 0; i < a.size(); ++i) {
    if (sum[findp(i)] < K) continue;

    if (best == -1) {
      best = i;
      continue;
    }

    Node &A = a[i], &B = a[best];
    if (A.q < B.q) best = i;
    else if ((A.q == B.q) && (A.r < B.r)) best = i;
    else if ((A.q == B.q) && (A.r == B.r) && (A.c < B.c)) best = i;
  }

  if (best == -1) return -1;
  return a[best].id;
}
