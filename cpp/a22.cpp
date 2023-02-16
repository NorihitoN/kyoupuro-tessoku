#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
int a[100009], b[100009];
int dp[100009];

int main() {

    cin >> n;
    for (int i = 1; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> b[i];
    dp[1] = 0;
    for (int i = 2; i <= n; i++) dp[i] = -100'000'000;

    for (int i = 1; i < n; i++)
    {
        dp[a[i]] = max(dp[a[i]], dp[i]+100);
        dp[b[i]] = max(dp[b[i]], dp[i]+150);
    }

    cout << dp[n];
    
    return 0;
}