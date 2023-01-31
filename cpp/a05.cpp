#include <iostream>
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ( k - i - j >= 1 && k - i - j <= n) count++;
        }
    }
    cout << count;
    return 0;
}