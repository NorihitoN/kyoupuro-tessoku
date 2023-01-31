#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int i = 0;
    int ans = 0;
    while (N > 0)
    {
        int digit = N % 10;
        N /= 10;
        ans += digit * (1<<i);
        i++;
    }
    cout << ans;
    return 0;
}