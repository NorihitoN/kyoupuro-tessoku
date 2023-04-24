#include <iostream>
#include <regex>
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
      if (par[x] == -1) {
        break;
      }
      x = par[x];
    }
    return x;
  }

  void unite(int u, int v) {
    int rootu = root(u);
    int rootv = root(v);
    if (rootu == rootv)
      return;
    if (siz[rootu] < siz[rootv]) {
      par[rootu] = rootv;
      siz[rootv] = siz[rootu] + siz[rootv];
    } else {
      par[rootv] = rootu;
      siz[rootu] = siz[rootv] + siz[rootu];
    }
  }

  bool same(int u, int v) {
    if (root(u) == root(v)) {
      return true;
    }
    return false;
  }
};

int N, Q;

int query[100009], u[100009], v[100009];

int main() {
  cin >> N >> Q;
  for (int i = 1; i <= Q; i++) {
    cin >> query[i] >> u[i] >> v[i];
  }

  UnionFind UF;
  UF.init(N);
  for (int i = 1; i <= Q; i++) {
    if (query[i] == 1) {
      UF.unite(u[i], v[i]);
    } else if (query[i] == 2) {
      if (UF.same(v[i], u[i])) {
        cout << "Yes" << endl;
      } else
        cout << "No" << endl;
    }
  }
  return 0;
}
