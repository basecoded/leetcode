#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
  int i; // ith array
  int j; // jth number in the array
  int val;
  bool operator()(const Node& node1, const Node& node2) {
    return node1.val > node2.val;
  }
};

int GetKSmall(const vector<vector<int>>& arrays, int m) {
  priority_queue<Node, vector<Node>, Node> min_heap;
  for (int i = 0; i < arrays.size(); i++) {
    if (arrays[i].size() > 0) {
      Node node { i, 0, arrays[i][0] };
      min_heap.push(node);
    }
  }
  while (--m) {
    Node node = min_heap.top();
    min_heap.pop();
    if (node.j + 1 < arrays[node.i].size()) {
      Node new_node { node.i, node.j + 1, arrays[node.i][node.j + 1] };
      min_heap.push(new_node);
    }
  }
  return min_heap.top().val;
}

int main() {
  vector<vector<int>> arrays;
  vector<int> v { 1, 4, 5 };
  vector<int> v1 { 2, 4, 6 };
  vector<int> v2 { 3, 5, 7 };
  arrays.push_back(v);
  arrays.push_back(v1);
  arrays.push_back(v2);
  cout << GetKSmall(arrays, 3) << endl;
  return 0;
}
