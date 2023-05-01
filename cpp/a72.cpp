#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int h, w, k;
int answer;
char c[19][109], d[19][109];

void paintCol(int steps) {
  // save num of '.' each column
  vector<pair<int, int>> columns;
  for (int j = 1; j <= w; j++) {
    int cnt = 0;
    for (int i = 1; i <= h; i++) {
      if (d[i][j] == '.')
        cnt += 1;
    }
    columns.push_back(make_pair(cnt, j));
  }
  // sort greater
  sort(columns.begin(), columns.end());
  reverse(columns.begin(), columns.end());

  // . -> #
  for (int j = 0; j < steps; j++) {
    for (int i = 1; i <= h; i++) {
      d[i][columns[j].second] = '#';
    }
  }
}

int main() {
  cin >> h >> w >> k;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> c[i][j];
    }
  }

  for (int t = 0; t < (1 << h); t++) {

    // Initalalize d[i][j]
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        d[i][j] = c[i][j];
      }
    }

    int remaining_paint_count = k;
    // . -> # in row pattern t
    for (int i = 1; i <= h; i++) {
      if ((t / (1 << (i - 1))) % 2) {
        for (int j = 1; j <= w; j++) {
          d[i][j] = '#';
        }
        remaining_paint_count -= 1;
      }
    }

    if (remaining_paint_count < 0)
      continue;

    // . -> # in k columns with the highest number of #'s
    if (remaining_paint_count > 0)
      paintCol(remaining_paint_count);

    // count all #
    int count = 0;
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        if (d[i][j] == '#')
          count += 1;
      }
    }

    answer = max(answer, count);
  }

  cout << answer << endl;
  return 0;
}
