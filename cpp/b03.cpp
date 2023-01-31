#include <iostream>
using namespace std;

int main() {
    int N;
    int A[109];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (A[i] + A[j] + A[k] == 1000 ) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
    return 0;
}