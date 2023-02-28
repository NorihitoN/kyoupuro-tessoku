#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


long long power(long long a, long long b, long long m) {
    long long aa = a;
    long long sum = 1;
    long long i = 0;
    while ((1 << i) <= b) {
        if ((b / (1 << i) % 2) == 1) {
            sum *= aa;
            sum %= m;
        } 
        aa = (aa * aa) % m;
        i++;
    }
    return sum;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << power(a, b, 1000'000'007);
    return 0;
}