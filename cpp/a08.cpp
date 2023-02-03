#include <iostream>
using namespace std;
 
int h, w, q;
int x[1509][1509];
int z[1509][1509];
int a[100009], b[100009], c[100009], d[100009];

int main() {
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> x[i][j];
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    for (int i = 0; i <= h; i++) {
        for (int j = 0; j <= w; j++) {
            z[i][j] = 0;
        }
    }

    for (int i = 1; i <= h; i++ ) {
        for ( int j = 1; j <= w; j++) {
            z[i][j] = z[i][j-1] + x[i][j];
        }
    }
    for ( int j = 1; j <= w; j++) {
        for (int i = 1; i <= h; i++ ) {
            z[i][j] = z[i-1][j] + z[i][j];
        }
    }

    for (int i = 1; i <= q; i++)
    {
        cout << z[c[i]][d[i]] - z[c[i]][b[i]-1] - z[a[i]-1][d[i]] + z[a[i]-1][b[i]-1] << endl;
    }


    return 0;
}