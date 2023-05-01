#include <algorithm>
#include <iostream>
using namespace std;

int n, a[69], b[69];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  reverse(b + 1, b + n + 1);

  int answer = 0;
  for (int i = 1; i <= n; i++) {
    answer += a[i] * b[i];
  }

  cout << answer << endl;

  return 0;
}
