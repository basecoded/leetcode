#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& v, int i, int n) {
  int left = INT_MIN, right = INT_MIN;
  if (2 * i  + 1< n)
    left = v[2 * i + 1];
  if (2 * i + 2 < n)
    right = v[2 * i + 2];
  int max_value = max(left, right);
  max_value = max(max_value, v[i]);
  if (max_value == left) {
    swap(v[i], v[2 * i + 1]);
    heapify(v, 2 * i + 1, n);
  } else if (max_value == right) {
    swap(v[i], v[2 * i + 2]);
    heapify(v, 2 * i + 2, n);
  }
}

void heapSort(vector<int>& v) {
  int n = v.size();
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(v, i, n);
  for (int i = n - 1; i >= 0; i--) {
    swap(v[0], v[i]);
    heapify(v, 0, i);
  }
}

int main() {
  vector<int> v { 2, 4, 6, 3, 5, 1, 9, 7, 8 };
  heapSort(v);
  for (auto i : v)
    cout << i << " ";
  cout << endl;
  return 0;
}
