#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int Q;
  cin >> Q;

  map<string, int> Map;

  for (int i = 0; i < Q; i++) {
    int query;
    cin >> query;
    if (query == 1) {
      string name;
      int value;
      cin >> name >> value;
      Map[name] = value;
    } else {
      string name;
      cin >> name;
      cout << Map[name] << endl;
    }
  }
  return 0;
}
