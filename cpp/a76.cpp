#include <algorithm>
#include <iostream>
using namespace std;

const int mod = 1'000'000'007;
int n, w, l, r;
int x[150009];
int dp[150009];
int sum[150009];

int main() {
  cin >> n >> w >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  x[0] = 0, x[n + 1] = w;

  dp[0] = 1;
  sum[0] = 1;
  for (int i = 1; i <= n + 1; i++) {
    int posL = lower_bound(x, x + n + 2, x[i] - r) - x;
    int posR = lower_bound(x, x + n + 2, x[i] - l + 1) - x;
    posR--;
    if (posR == -1)
      dp[i] = 0;
    else
      dp[i] = sum[posR];
    if (posL >= 1)
      dp[i] -= sum[posL - 1];
    dp[i] = (dp[i] + mod) % mod;

    sum[i] = sum[i - 1] + dp[i];
    sum[i] %= mod;
  }

  cout << dp[n+1] << endl;
  return 0;
}
