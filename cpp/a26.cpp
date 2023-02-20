// エラトルテネス
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int q, x[10009];
int n = 300000;
bool deleted[300009];

int main()
{

    cin >> q;
    for (int i = 1; i <= q; i++) cin >> x[i];
    for (int i = 2; i <= n; i++) deleted[i] = false;

    
    for (int i = 2; i*i <= n; i++) {
        if (deleted[i] == true) continue;
        for (int j = i * 2; i * j <= n; j++) deleted[i*i] = true;
    }
    
    cin >> h >> w;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> c[i][j];
        }
    }

    dp[1][1] = 1;
    for (int j = 2; j <= w; j++) {
        if (c[1][j] == '#') dp[1][j] = 0;
        else dp[1][j] = dp[1][j-1];
    }

    
    for (int i = 2; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (c[i][j] == '#') dp[i][j] = 0;
            else {
                if (i == 1) {
                    dp[i][j] = dp[i][j-1];
                } else if (j == 1) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
    }
    cout << dp[h][w];
    return 0;
}