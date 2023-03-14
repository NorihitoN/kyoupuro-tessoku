#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  priority_queue<int, vector<int>, greater<int>> pq;
  int Q;
  cin >> Q;

  for (int num = 0; num < Q; num++) {
    int query;
    cin >> query;
    if (query == 1) {
      int data;
      cin >> data;
      pq.push(data);
    } else if (query == 2) {
      cout << pq.top() << endl;
    } else {
      pq.pop();
    }
  }

  return 0;
}
