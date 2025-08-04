#include <bits/stdc++.h>
using namespace std;

int lc[27];
int rc[27];

char alphabet(int n) {
  return 'A' + n;
}

void postorder(int cur) {
  if (alphabet(cur) == '.') return;
  postorder(lc[cur]);
  postorder(rc[cur]);
  cout << alphabet(cur);
}

void inorder(int cur) {
  if (alphabet(cur) == '.') return;
  inorder(lc[cur]);
  cout << alphabet(cur);
  inorder(rc[cur]);
}

void preorder(int cur) {
  if (alphabet(cur) == '.') return;
  cout << alphabet(cur);
  preorder(lc[cur]);
  preorder(rc[cur]);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    char p, l, r;
    cin >> p >> l >> r;
    lc[p - 'A'] = l - 'A';
    rc[p - 'A'] = r - 'A';
  }

  preorder(0); cout << '\n';
  inorder(0); cout << '\n';
  postorder(0);
}
