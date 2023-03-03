#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, n;
    cin >> n >> a >> b;

    bool dp[100009];
    for (int i = 0; i <= n; i++) {
        if (i >= a && dp[i-a] == false) dp[i] = true;
        else if (i >= b && dp[i-b] == false) dp[i] = true;
        else dp[i] = false;
    }
    
    if (dp[n] == true) cout << "First";
    else cout << "Second";
    
}
