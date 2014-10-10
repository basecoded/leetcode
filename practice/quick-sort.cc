#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int>& v, int start, int end) {
  int pivot = v[end];
  int i = start;
  for (int j = start; j < end; j++) {
    if (v[j] <= pivot)
      swap(v[i++], v[j]);
  }
  swap(v[i], v[end]);
  return i;
}

  void QuickSort(vector<int>& v, int start, int end) {
    if (start >= end)
      return;
    int mid = Partition(v, start, end);
    QuickSort(v, start, mid - 1);
    QuickSort(v, mid + 1, end);
  }

int main() {
  vector<int> v { 2, 5, 2, 6, 7, 1, 4, 7, 3, 8, 9 };
  QuickSort(v, 0, v.size() - 1);
  for (auto const i : v)
    cout << i << " ";
  cout << endl;
  return 0;
}
