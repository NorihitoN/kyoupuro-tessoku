#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)



int gcd(int a, int b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int main()
{
    int a, b;

    cin >> a >> b;

    int ans = gcd(a, b);
    cout << ans;
    
    return 0;
}