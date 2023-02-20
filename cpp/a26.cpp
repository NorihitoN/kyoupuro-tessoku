// エラトルテネス
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int q, x[10009];
int n = 300000;
bool deleted[300009];

int main()
{

    cin >> q;
    for (int i = 1; i <= q; i++) cin >> x[i];
    for (int i = 2; i <= n; i++) deleted[i] = false;

    
    for (int i = 2; i*i <= n; i++) {
        if (deleted[i] == true) continue;
        for (int j = i * 2; j <= n; j += i) deleted[j] = true;
    }

    for (int i = 1; i <= q; i++)
    {
        if (deleted[x[i]] == false) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}