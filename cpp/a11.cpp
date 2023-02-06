#include <iostream>

using namespace std;

int n, x;
int a[100009];
int main() {

    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int l = 1;
    int r = n;
    while(l < r) {
        int m = (l + r) / 2;
        if (x <= a[m]) r = m;
        else l = m + 1;
    }
    cout << l;
    return 0;
}