#include <iostream>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    int A;
    for (size_t i = 0; i < N; i++)
    {
        cin >> A;
        if (A == X) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}