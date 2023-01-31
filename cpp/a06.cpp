#include <iostream>
using namespace std;
 
int main() {
    int n, q;
    int a[100009], s[100009];
    s[0] = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    int l, r;
    for (int j = 0; j < q; j++)
    {
        cin >> l >> r;
        cout << s[r] - s[l-1] << endl;
    }
    return 0;
}