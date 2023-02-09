#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int a[1009];
int b[1009];
int c[1009];
int d[1009];
int p[1000009];
int q[1000009];

int main() {

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> d[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p[i*n+j] = a[i] + b[j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            q[i*n+j] = c[i] + d[j];
        }
    }
    sort(q, q+n*n);

    for (int i = 0; i < n*n; i++)
    {
        int pos = lower_bound(q, q+n*n, k-p[i]) - q;
        if (pos<n*n && q[pos] == k - p[i]) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    
    return 0;
}