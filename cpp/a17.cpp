#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[100009];
int b[100009];
int dp[100009];
vector<int> ans;

int main() {

    cin >> n;
    for (int i = 2; i <= n; i++) cin >> a[i];
    for (int i = 3; i <= n; i++) cin >> b[i];

    dp[1] = 0;
    dp[2] = a[2];
    for (int i = 3; i <= n; i++)
    {
        dp[i] = min(dp[i-1]+a[i], dp[i-2]+b[i]);
    }
    int r = n;
    while(true) {
        ans.push_back(r);
        if (r <= 1) break;

        if (dp[r-1] + a[r] == dp[r]) r -= 1;
        else r -= 2;
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        if (i >= 1) cout << " ";
        cout << ans[i];
    }

    return 0;
}