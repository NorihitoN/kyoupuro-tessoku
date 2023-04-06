#include <iostream>
using namespace std;

class SegmentTree {
public:
  int dat[300000];
  int siz = 1;

  void init(int N) {
    siz = 1;
    while (siz < N) {
      siz *= 2;
    }
    for (int i = 1; i < siz * 2; i++) {
      dat[i] = 0;
    }
  }

  void update(int pos, int x) {
    pos += siz - 1;
    dat[pos] = x;
    while (pos >= 2) {
      pos /= 2;
      dat[pos] = dat[2 * pos] + dat[2 * pos + 1];
    }
  }

  int query(int l, int r, int a, int b, int u) {
    if (r <= a || b <= l)
      return 0;
    if (l <= a && b <= r)
      return dat[u];
    int m = (a + b) / 2;
    int ansL = query(l, r, a, m, 2 * u);
    int ansR = query(l, r, m, b, 2 * u + 1);
    return ansL + ansR;
  }
};

int N, Q;
SegmentTree Z;

int main() {
  cin >> N >> Q;
  Z.init(N);

  for (int i = 0; i < Q; i++) {
    int c;
    cin >> c;
    if (c == 1) {
      int pos, x;
      cin >> pos >> x;
      Z.update(pos, x);
    } else if (c == 2) {
      int l, r;
      cin >> l >> r;
      cout << Z.query(l, r, 1, Z.siz + 1, 1) << endl;
    }
  }

  return 0;
}
