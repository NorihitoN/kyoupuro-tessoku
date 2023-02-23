#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int n;
char t[100009];
int a[100009];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> a[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i] == '+') ans += a[i];
        if (t[i] == '-') ans -= a[i];
        if (t[i] == '*') ans *= a[i];

        if ( ans < 0 ) ans += 10000;
        ans %= 10000;
        cout << ans << endl;
    }
    return 0;
}