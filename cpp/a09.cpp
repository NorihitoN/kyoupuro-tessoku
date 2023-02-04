#include <iostream>
using namespace std;
 
int h, w, n;
int x[1509][1509];
int z[1509][1509];
int a,b,c,d;

int main() {
    cin >> h >> w >> n;
    for (int i = 0; i < h+1; i++) {
        for (int j = 0; j < w+1; j++) {
            x[i][j] = 0;
            z[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        x[a-1][b-1]++; x[a-1][d]--; x[c][b-1]--; x[c][d]++; 
    }


    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            z[i][j] = z[i][j-1] + x[i-1][j-1];
        }
    }
    for (int j = 1; j <= w; j++) {
        for (int i = 1; i <= h; i++) {
            z[i][j] += z[i-1][j];
        }
    }

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (j >= 2) {
                cout << " ";
            }
            cout << z[i][j];
        }
        cout << endl;
    }
    

    return 0;
}