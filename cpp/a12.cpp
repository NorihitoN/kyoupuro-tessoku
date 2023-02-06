#include <iostream>

using namespace std;

long n, k;
long a[100009];

bool check(long m) {
    long sum = 0;
    for (long i = 1; i <= n; i++)
    {
        sum += m / a[i];
    }
    return sum >= k;
}

int main() {

    cin >> n >> k;
    for (long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    long l = 1;
    long r = 1000000000;
    while(l < r) {
        long m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m + 1;
    }
    cout << l;
    return 0;
}