#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

int main()
{
    int q;
    cin >> q;
    queue<string> data_queue;
    for (int i = 0; i < q; i++) {
        
        int query;
        cin >> query;
        if(query == 1) {
            string name;
            cin >> name;
            data_queue.push(name);
        } else if (query == 2) {
            cout << data_queue.front() << endl;
        } else {
            data_queue.pop();
        }

    }
    return 0;
}
