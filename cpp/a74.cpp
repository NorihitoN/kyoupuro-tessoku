#include <iostream>
using namespace std;

int n, p[109][109];
int x[109], y[109];
int inverseX, inverseY;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> p[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (p[i][j] != 0) {
        x[i] = p[i][j];
        y[j] = p[i][j];
      }
    }
  }

  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (x[i] > x[j])
        inverseX++;
      if (y[i] > y[j])
        inverseY++;
    }
  }

  cout << inverseX + inverseY << endl;
  return 0;
}
