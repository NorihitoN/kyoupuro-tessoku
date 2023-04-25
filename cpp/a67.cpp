#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class UnionFind {
public:
  int par[100009];
  int siz[100009];

  void init(int n) {
    for (int i = 1; i <= n; i++) {
      par[i] = -1;
      siz[i] = 1;
    }
  }

  int root(int x) {
    while (true) {
      if (par[x] == -1)
        break;
      x = par[x];
    }
    return x;
  }

  void unite(int u, int v) {
    int rootu = root(u);
    int rootv = root(v);
    if (siz[rootu] < siz[rootv]) {
      par[rootu] = rootv;
      siz[rootv] = siz[rootv] + siz[rootu];
    } else {
      par[rootv] = rootu;
      siz[rootu] = siz[rootv] + siz[rootu];
    }
  }

  bool same(int u, int v) {
    if (root(u) == root(v))
      return true;
    return false;
  }
};

int N, M;
int A[100009], B[100009], C[100009];

int main() {
  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    cin >> A[i] >> B[i] >> C[i];
  }
  vector<pair<int, int>> V;
  for (int i = 1; i <= M; i++) {
    V.push_back(make_pair(C[i], i));
  }
  sort(V.begin(), V.end());

  UnionFind UF;
  UF.init(N);
  int sum = 0;
  for (int i = 0; i < V.size(); i++) {
    int idx = V[i].second;
    if (UF.same(A[idx], B[idx]))
      continue;
    sum += C[idx];
    UF.unite(A[idx], B[idx]);
  }

  cout << sum << endl;

  return 0;
}
