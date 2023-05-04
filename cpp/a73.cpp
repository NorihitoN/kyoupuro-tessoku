#include <functional>
#include <iostream>
#include <ostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// input
int n, m, a[100009], b[100009], c[100009], d[100009];
vector<pair<int, int>> G[8009];

// Dijkstra algorithm
long long cur[8009];
bool kakutei[8009];
priority_queue<pair<long long, int>, vector<pair<long long, int>>,
               greater<pair<long long, int>>>
    Q;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    G[a[i]].push_back(make_pair(b[i], c[i] * 10000 - d[i]));
    G[b[i]].push_back(make_pair(a[i], c[i] * 10000 - d[i]));
  }

  for (int i = 1; i <= n; i++) {
    kakutei[i] = false;
    cur[i] = (1LL << 60);
  }

  cur[1] = 0;
  Q.push(make_pair(cur[1], 1));

  while (!Q.empty()) {
    int pos = Q.top().second;
    Q.pop();
    if (kakutei[pos] == true)
      continue;

    kakutei[pos] = true;

    for (int i = 0; i < G[pos].size(); i++) {
      int next = G[pos][i].first;
      int cost = G[pos][i].second;
      if (cur[next] > cur[pos] + cost) {
        cur[next] = cur[pos] + cost;
        Q.push(make_pair(cur[next], next));
      }
    }
  }

  long long dist = cur[n] / 10000 + 1;
  int tree = dist * 10000 - cur[n];
  cout << dist << " " << tree << endl;

  return 0;
}
