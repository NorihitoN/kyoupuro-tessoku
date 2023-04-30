#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, a[19];
int m, x[109], y[109], z[109];

int dist[1030];
vector<int> g[1030];

int getNext(int pos, int idx) {
  int state[19]; // posを2進法で表現するための各ビット状態
  for (int i = 1; i <= n; i++) {
    state[i] = (pos / (1 << (i - 1))) % 2;
  }
  state[x[idx]] = 1 - state[x[idx]];
  state[y[idx]] = 1 - state[y[idx]];
  state[z[idx]] = 1 - state[z[idx]];

  int ret = 0;
  for (int i = 1; i <= n; i++) {
    if (state[i] == 1)
      ret += (1 << (i - 1));
  }
  return ret;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= m; i++)
    cin >> x[i] >> y[i] >> z[i];

  for (int i = 0; i < (1 << n); i++) {
    for (int j = 1; j <= m; j++) {
      int nextState = getNext(i, j);
      g[i].push_back(nextState);
    }
  }

  int goal = (1 << n) - 1;
  int start = 0;
  for (int i = 1; i <= n; i++) {
    start += a[i] * (1 << (i - 1));
  }

  queue<int> Q;
  for (int i = 0; i < (1 << n); i++)
    dist[i] = -1;
  Q.push(start);
  dist[start] = 0;

  while (!Q.empty()) {
    int pos = Q.front();
    Q.pop();
    for (int i = 0; i < g[pos].size(); i++) {
      int to = g[pos][i];
      if (dist[to] == -1) {
        dist[to] = dist[pos] + 1;
        Q.push(to);
      }
    }
  }

  cout << dist[goal] << endl;

  return 0;
}
