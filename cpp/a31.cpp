#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;

    long long ans = (n/3) + (n/5) - (n/15);
    cout << ans;
}
