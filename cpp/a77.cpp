#include <iostream>
using namespace std;

int N, L, K;
int a[100009];

bool check(int x) {
  int count = 0, last_kireme = 0;
  for (int i = 1; i <= N; i++) {
    if (a[i] - last_kireme >= x && L - a[i] >= x) {
      last_kireme = a[i];
      count++;
    }
  }
  if (count >= K) { return true; }
  else return false;
}

int main() {
  cin >> N >> L >> K;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  int l = 1, r = 1'000'000'000;
    int c = 0;
  while (l < r) {
    int m = (l + r) / 2 + 1;
    // cout << c << ": " << m << endl;
    if (check(m))
      l = m;
    else
      r = m - 1;
    c++;
  }

  cout << l << endl;

  return 0;
}
