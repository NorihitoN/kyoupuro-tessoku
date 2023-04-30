#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int to, cap, rev;
};

class MaximumFlow {
public:
  int size_ = 0;
  bool used[409];
  vector<Edge> G[409];

  void init(int N) {
    size_ = N;
    for (int i = 0; i <= size_; i++) {
      G[i].clear();
    }
  }

  void add_edge(int a, int b, int c) {
    int cur_Ga = G[a].size();
    int cur_Gb = G[b].size();
    G[a].push_back(Edge{ b, c, cur_Gb });
    G[b].push_back(Edge{ a, 0, cur_Ga });
  }

  int dfs(int pos, int goal, int F) {
    if (pos == goal)
      return F;
    used[pos] = true;

    for (int i = 0; i < G[pos].size(); i++) {
      if (G[pos][i].cap == 0)
        continue;
      if (used[G[pos][i].to] == true)
        continue;
      int flow = dfs(G[pos][i].to, goal, min(F, G[pos][i].cap));

      if (flow >= 1) {
        G[pos][i].cap -= flow;
        G[G[pos][i].to][G[pos][i].rev].cap += flow;
        return flow;
      }
    }
    return 0;
  }

  int max_flow(int s, int t) {
    int total_flow = 0;
    while (true) {
      for (int i = 0; i <= size_; i++) {
        used[i] = false;
      }

      int F = dfs(s, t, 1000000000);
      if (F == 0)
        break;
      total_flow += F;
    };
    return total_flow;
  }
};

int N;
char c[159][159];
MaximumFlow Z;

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> c[i][j];
    }
  }

  Z.init(2 * N + 2);

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (c[i][j] == '#')
        Z.add_edge(i, N + j, 1);
    }
  }

  for (int i = 1; i <= N; i++) {
    Z.add_edge(2 * N + 1, i, 1);
    Z.add_edge(N + i, 2 * N + 2, 1);
  }

  cout << Z.max_flow(2 * N + 1, 2 * N + 2) << endl;

  return 0;
}

