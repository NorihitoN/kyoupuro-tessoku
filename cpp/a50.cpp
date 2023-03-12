#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int N = 100;
int Q = 1000;
int A[109][109];
int B[109][109];
int X[1009], Y[1009], H[1009];

int RandInt(int a, int b) { return rand() % (b - a + 1) + a; }

int GetScore() {
  int sum = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      sum += abs(A[i][j] - B[i][j]);
  }
  return 200'000'000 - sum;
}

void Change(int t, int x, int y, int h) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      B[j][i] -= max(0, H[t] - abs(X[t] - i) - abs(Y[t] - j));
    }
  }
  X[t] = x;
  Y[t] = y;
  H[t] = h;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      B[j][i] += max(0, H[t] - abs(X[t] - i) - abs(Y[t] - j));
    }
  }
}

void Yamanobori() {
  int TIME_LIM = 5.95 * CLOCKS_PER_SEC;
  int CurrentScore = GetScore();
  int ti = clock();

  while (clock() - ti < TIME_LIM) {
    int t = RandInt(1, Q);
    int old_x = X[t], new_x = X[t] + RandInt(-9, 9);
    int old_y = Y[t], new_y = Y[t] + RandInt(-9, 9);
    int old_h = H[t], new_h = H[t] + RandInt(-19, 19);
    if (new_x < 0 || new_x >= N)
      continue;
    if (new_y < 0 || new_y >= N)
      continue;
    if (new_h <= 0 || new_h > N)
      continue;

    Change(t, new_x, new_y, new_h);
    int NewScore = GetScore();

    if (CurrentScore < NewScore)
      CurrentScore = NewScore;
    else
      Change(t, old_x, old_y, old_h);
  }
}

int main() {
  for (int i; i < N; i++) {
    for (int j; j < N; j++) cin >> A[i][j];
  }

  for (int i = 1; i <= 1000; i++) {
    X[i] = rand() % N;
    Y[i] = rand() % N;
    H[i] = 1;
    B[Y[i]][X[i]] += 1;
  }

  Yamanobori();

  cout << "1000" << endl;
  for (int i = 1; i <= 1000; i++) {
    cout << X[i] << " " << Y[i] << " " << H[i] << endl;
  }
  return 0;
}
