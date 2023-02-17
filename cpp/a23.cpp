#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, m;
int a[109][19];
int dp[109][1024];

int main()
{

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    rep(i, m + 1)
    {
        rep(j, ((1 << n) + 1))
        {
            dp[i][j] = 1'000'000'000;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < 1 << n; j++)
        {
            int already[19];
            for (int k = 1; k <= n; k++)
            {
                if (j / (1 << (k - 1)) % 2 == 0)
                    already[k] = 0;
                else
                    already[k] = 1;
            }
            int v = 0;
            for (int k = 1; k <= n; k++)
            {
                if (already[k] == 1 || a[i][k] == 1)
                    v += 1 << (k - 1);
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            dp[i][v] = min(dp[i][v], dp[i - 1][j] + 1);
        }
    }

    if (dp[m][(1 << n) - 1] == 1'000'000'000)
        cout << "-1";
    else
        cout << dp[m][(1 << n) - 1];

    return 0;
}