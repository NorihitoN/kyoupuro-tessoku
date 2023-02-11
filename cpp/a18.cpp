#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, s;
int a[69];
int dp[69][100009];

int main() {

    cin >> n >> s;
    for (int j = 1; j <= n; j++) cin >> a[j];
    dp[0][0] = 1;
    for (int j = 1; j <= s; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if(j < a[i]) {
                if (dp[i-1][j] == 1) dp[i][j] =1;
                else dp[i][j] = 0;
            } else {
                if (dp[i-1][j] == 1 || dp[i-1][j-a[i]] == 1) dp[i][j] =1;
                else dp[i][j] = 0;
            }
        }
    }

    if(dp[n][s] == 1) cout << "Yes";
    else cout << "No";


    return 0;
}