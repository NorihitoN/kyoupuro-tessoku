#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int A[100009], B[100009], C[100009];
vector<pair<int, int>> G[100009];

//
// Dijkstra algorithm
//
int dist[100009];
bool kakutei[100009];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    Q;

int main() {
  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    cin >> A[i] >> B[i] >> C[i];
    G[A[i]].push_back(make_pair(B[i], C[i]));
    G[B[i]].push_back(make_pair(A[i], C[i]));
  }

  for (int i = 1; i <= N; i++) {
    kakutei[i] = false;
    dist[i] = 2000000000;
  }

  dist[1] = 0;
  Q.push(make_pair(dist[1], 1));

  while (!Q.empty()) {
    int from = Q.top().second;
    Q.pop();

    if (kakutei[from] == true) {
      continue;
    }
    kakutei[from] = true;
    for (int i = 0; i < G[from].size(); i++) {
      int to = G[from][i].first;
      int cost = G[from][i].second;
      if (dist[to] > dist[from] + cost) {
        dist[to] = dist[from] + cost;
        Q.push(make_pair(dist[to], to));
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    if (dist[i] == 2000000000)
      cout << "-1" << endl;
    else
      cout << dist[i] << endl;
  }

  return 0;
}
