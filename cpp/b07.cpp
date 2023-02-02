#include <iostream>
using namespace std;
 
int t, n;
int l[500009], r[500009];
int a[500009], s[500009];

int main() {
    cin >> t >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }
    for (int i = 1; i <= n; i++) {
        a[l[i]+1]++;
        a[r[i]+1]--;
    }
    s[0] = 0;
    for (int i = 1; i <= t; i++) {
        s[i] = s[i-1] + a[i];
        cout << s[i] << endl;
    }
    return 0;
}