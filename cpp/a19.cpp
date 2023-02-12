#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, W;
long long w[109];
long long v[109];
long long dp[109][100009];

int main() {

    cin >> N >> W;
    for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = - 1'000'000'000'000LL;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if(j < w[i]) {
                dp[i][j] = dp[i-1][j];
            }else {
                dp[i][j] = max(dp[i-1][j-w[i]] + v[i], dp[i-1][j]);
            }
        }
    }

    long long ans = 0LL;
    for (int j =0; j<= W; j++) ans = max(ans, dp[N][j]);

    cout << ans;

    return 0;
}