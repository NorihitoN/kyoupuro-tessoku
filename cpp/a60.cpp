#include <iostream>
#include <stack>
using namespace std;

int N, A[200009];
int Answer[200009];
stack<pair<int, int>> Level2;

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  for (int i = 1; i <= N; i++) {
    if (i >= 2) {
      Level2.push(make_pair(i - 1, A[i - 1]));

      while (!Level2.empty()) {
        int kabuka = Level2.top().second;
        if (kabuka <= A[i]) {
          Level2.pop();
        } else
          break;
        }
    }
    if (!Level2.empty()) {
      Answer[i] = Level2.top().first;
    } else {
      Answer[i] = -1;
    }
  }

  for (int i = 1; i <= N; i++) {
    if (i >= 2) cout << " ";
    cout << Answer[i];
  }

  return 0;
}
