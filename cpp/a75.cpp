#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int n, t[109], d[109];

int dp[109][1449];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> d[i];
  }

  vector<pair<int, int>> prob;
  for (int i = 1; i <= n; i++) {
    prob.push_back(make_pair(d[i], t[i]));
  }

  sort(prob.begin(), prob.end());
  for (int i = 1; i <= n; i++) {
    t[i] = prob[i - 1].second;
    d[i] = prob[i - 1].first;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 1440; j++) {
      dp[i][j] = -1;
    }
  }

  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 1440; j++) {
      if (j < t[i] || d[i] < j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + 1);
    }
  }

  int answer = 0;
  for (int i = 1; i <= 1440; i++) {
    answer = max(answer, dp[n][i]);
  }
  cout << answer << endl;

  return 0;
}
