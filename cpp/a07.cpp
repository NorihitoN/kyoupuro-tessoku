#include <iostream>
using namespace std;
 
int d, n;
int l[100009], r[100009];
int a[100009], s[100009];

int main() {
    cin >> d >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }
    for (int i = 1; i <= n; i++) {
        a[l[i]]++;
        a[r[i]+1]--;
    }
    s[0] = 0;
    for (int i = 1; i <= d; i++) {
        s[i] = s[i-1] + a[i];
        cout << s[i] << endl;
    }
    return 0;
}