#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() { 

    stack<string> stack_data;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;
        if (query == 1) {
            string data;
            cin >> data;
            stack_data.push(data);
        } else if (query == 2) {
            cout << stack_data.top() << endl;
        } else {
            stack_data.pop();
        }
    }

    return 0;
}
