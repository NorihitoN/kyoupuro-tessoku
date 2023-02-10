#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[100009];
int b[100009];

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> T;
    for (int i = 1; i<= n; i++) T.push_back(a[i]);
    sort(T.begin(), T.end());
    T.erase(unique(T.begin(), T.end()), T.end());

    for (int i = 1; i<=n; i++) {
        b[i] = lower_bound(T.begin(), T.end(), a[i]) - T.begin();
        b[i]++;
    }
    for (int i = 1; i <= n; i++) {
        if (i >= 2) cout << " ";
        cout << b[i];
    }
    return 0;
}