#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
  int q;
  cin >> q;
  std::set<int> s;
  for (int i = 0; i < q; i++) {
    int query, value;
    cin >> query >> value;
    if (query == 1) {
      s.insert(value);
    } else if (query == 2) {
      s.erase(value);
    } else {
      auto it = s.lower_bound(value);
      if (it == s.end())
        cout << -1 << endl;
      else
        cout << *it << endl;
    }
  }
  return 0;
}
