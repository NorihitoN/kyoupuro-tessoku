#include <iostream>
using namespace std;

int N, Q;
int A[100009], X[100009], Y[100009];
int dp[32][100009];

int main()
{
    
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) { cin >> A[i]; }
    for (int j = 1; j <=Q; j++) { cin >> X[j] >> Y[j]; }

    for (int i = 1; i <= N; i++) { dp[0][i] = A[i]; }
    for (int d = 1; d <= 29; d++) {
        for (int i = 1; i <= N; i++) {
            dp[d][i] = dp[d-1][dp[d-1][i]];
        }
    }

    for (int j = 1; j <= Q; j++) {
        int currentPos = X[j];
        for (int d = 29; d >= 0; d--) {
            if((Y[j] / (1 << d)) % 2 != 0) currentPos = dp[d][currentPos];
        }
        cout << currentPos << endl;
    }
    return 0;
}
