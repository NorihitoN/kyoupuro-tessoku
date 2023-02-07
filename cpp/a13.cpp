#include <iostream>

using namespace std;

long n, k;
long a[100009];

int main() {

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long sum = 0;
    int j = 1;
    for (int i = 0; i < n-1; i++)
    {
        while((j < n) && (a[j] <= a[i] + k)) {
            j++;
        }
        sum += j - i - 1;
    }
    
    cout << sum;
    return 0;
}