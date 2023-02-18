#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n;
int a[100009];
int l[100009];
int dp[100009];
int LEN = 0;

int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(l+1, l+LEN+1, a[i]) - l;
        dp[i] = pos;

        l[dp[i]] = a[i];
        if (dp[i] > LEN) LEN += 1;
    }
    cout << LEN;

    return 0;
}