#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// If M is a prime number and b % M != 0,
// (a / b) % M == (a * b^(M-2)) % M

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

long long divide(long long a, long long b, long long m) {
    return (a * power(b, m - 2, m) % m );
}

long long factorial(long long n, long long m) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1, m) % m;
    }
}

int main()
{
    long long n, r;
    long long m = 1000'000'007;
    long long ans;
    cin >> n >> r;

    long long nume = factorial(n, m);
    long long deno1 = factorial(r, m);
    long long deno2 = factorial(n-r, m);
    long long deno = deno1 * deno2 % m;

    ans = divide(nume, deno, m);

    cout << ans << endl;
    return 0;
}