#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Comp {
  bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
  }
};

vector<int> MergeKSortedArray(const vector<vector<int>>& arrays) {
  int n = arrays.size();
  vector<int> idx(n, 0);
  priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> q;
  for (int i = 0; i < arrays.size(); i++) {
    if (arrays[i].size() > 0)
      q.push(make_pair(arrays[i][0], i));
  }
  vector<int> result;
  while (!q.empty()) {
    pair<int, int> node = q.top();
    q.pop();
    result.push_back(node.first);
    if (++idx[node.second] < arrays[node.second].size())
      q.push(make_pair(arrays[node.second][idx[node.second]], node.second));
  }
  return result;
}

int main() {
  vector<vector<int>> arrays {{1, 4, 7, 10, 13}, {2, 5, 8, 11, 14}, {3, 6, 9, 12, 15}};
  vector<int> result = MergeKSortedArray(arrays);
  for (const auto a : result)
    cout << a << " ";
  cout << endl;
  return 0;
}
