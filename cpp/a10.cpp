#include <iostream>
using namespace std;
 
int n, d;
int a[100009];
int x[100009], y[100009];
int l[100009], r[100009];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> d;
    for (int i = 0; i < d; i++)
    {
        cin >> l[i] >> r[i];
    }
    x[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        x[i] = max(x[i-1], a[i]);
    }
    y[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        y[i] = max(y[i+1], a[i]);
    }

    for (int i = 0; i < d; i++)
    {
        cout << max(x[l[i]-2], y[r[i]]) << endl;
    }
    

    return 0;
}