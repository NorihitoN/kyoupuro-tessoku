#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    for (int i = A; i <= B; i++)
    {
        if (100 % i == 0) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}