#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
  #define BUCKET_SIZE 100 // bucket size

  struct Node { int id, r, c, h, w; }; // 노드 = 사각형
  int L_, N_;
  int B_; // 버킷 한 변 개수
  int groupCnt;

  vector<Node> a; // 노드 배열
  vector<int> p; // DSU. 부모노드 배열. 음수는 size.
  vector<int> buckets[5005 / BUCKET_SIZE][5005 / BUCKET_SIZE];

  int findp(const int &x) {
    if (p[x] < 0) return x;
    return p[x] = findp(p[x]); // 경로압축
  }

  bool unite(const int &x, const int &y) {
    int rootx = findp(x), rooty = findp(y);
    if (rootx == rooty) return false; // 이미 같은 그룹

    if (-p[rootx] < -p[rooty]) swap(rootx, rooty); // union-by-size
    p[rootx] += p[rooty]; // 먼저 size
    p[rooty] = rootx; // rooty를 rootx 자식으로
    return true;
  }

  bool is_overlap(const Node &A, const Node &B) {
    if (B.r + B.h <= A.r || B.r >= A.r + A.h) return false;
    if (B.c + B.w <= A.c || B.c >= A.c + A.w) return false;
    return true;
  }
}


void init(int L, int N){
  L_ = L; N_ = N;
  B_ = (N_ + BUCKET_SIZE - 1) / BUCKET_SIZE; // ceil(N_ / BUCKET_SIZE)
  a.clear(); p.clear();
  for (int i = 0; i < 5005 / BUCKET_SIZE; ++i) {
    for (int j = 0; j < 5005 / BUCKET_SIZE; ++j) buckets[i][j].clear();
  }
}

int draw(int mID, int mRow, int mCol, int mHeight, int mWidth){
  Node n = { mID, mRow, mCol, mHeight, mWidth };
  int idx = a.size();
  a.push_back(n);
  p.push_back(-1);

  int br = mRow / BUCKET_SIZE;
  int bc = mCol / BUCKET_SIZE;

  // 버킷에 넣기 전 버킷 돌며 union.
  for (int dr = -1; dr <= 1; ++dr) {
    int nr = br + dr;
    if (nr < 0 || nr >= B_) continue;
    for (int dc = -1; dc <= 1; ++dc) {
      int nc = bc + dc;
      if (nc < 0 || nc >= B_) continue;

      // 버킷 돌며
      for (int j : buckets[nr][nc]) {
        // 겹치는 사각형이라면 union  
        if (is_overlap(a[idx], a[j])) unite(idx, j);
      }
    }
  }

  buckets[br][bc].push_back(idx);
  return -p[findp(idx)]; // 사각형 개수는 루트노드의 부모. -size
}

int getRectCount(int mID){
  for (int i = 0; i < a.size(); ++i) {
    if (a[i].id == mID) return -p[findp(i)];
  }
  return 0;
}

int countGroup(){
  int cnt = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (p[i] < 0) ++cnt;
  }
  return cnt;
}
