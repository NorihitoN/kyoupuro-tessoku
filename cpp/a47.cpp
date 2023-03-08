#include <iostream>
#include <cmath>
using namespace std;

int x[159], y[159];
int path[159];
bool visited[159];
int n;

double get_distance(int p, int q) {
    return sqrt((x[p] - x[q]) * (x[p] - x[q]) + (y[p] - y[q]) * (y[p] - y[q]));
}

void greedy() {
    int now = 1;
    for (int i = 1; i <= n; i++) { visited[i] = false; }
    path[1] = 1;
    visited[1] = true;

    for (int i = 2; i <= n; i++) {
        int min_dist = 1000'000;
        int min_pos = -1;
        for (int j = 1; j <= n; j++) {
            if( visited[j] == true) continue;
            double new_dist = get_distance(now, j);
            if (min_dist > new_dist) {
                min_pos = j;
                min_dist = new_dist;
            }
        }
        visited[min_pos] = true;
        path[i] = min_pos;
        now = min_pos;
    }
    path[n+1] = 1;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    greedy();

    for (int i = 1; i <= n+1; i++) {
        cout << path[i] << endl;
    }
    
    return 0;
}

