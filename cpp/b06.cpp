#include <iostream>
using namespace std;
 
int main() {
    int n, q;
    int a[100009], win[100009], lose[100009];
    win[0] = 0; lose[0] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i<= n; i++)
    {
        if (a[i] == 1) {
            win[i] = win[i-1] + 1;
            lose[i] = lose[i-1];
        } else {
            win[i] = win[i-1];
            lose[i] = lose[i-1] + 1;
        }
    }

    cin >> q;
    int l, r;
    for (int j = 0; j < q; j++)
    {
        cin >> l >> r;
        int w = win[r] - win[l-1];
        int lo = lose[r] - lose[l-1];
        if (w - lo > 0) {cout << "win" << endl;}
        else if (w - lo < 0) { cout << "lose" << endl;}
        else { cout << "draw" << endl; }
    }
    return 0;
}