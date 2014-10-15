#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int>& v, int start, int end) {
  int pivot = v[end];
  int idx = start;
  for (int i = start; i < end; i++) {
    if (v[i] <= pivot)
      swap(v[idx++], v[i]);
  }
  swap(v[idx], v[end]);
  return idx;
}

int FindKthLarge(vector<int>& v, int low, int high, int k) {
  if (low >= high)
    return v[low];
  int mid = Partition(v, low, high);
  if (mid > k)
    return FindKthLarge(v, low, mid - 1, k);
  else if (mid < k)
    return FindKthLarge(v, mid + 1, high, k);
  else
    return v[mid];
}

int main() {
  vector<int> v { 1,2,3,4,5 };
  for (int i = 1; i <= 5; i++)
    cout << FindKthLarge(v, 0, v.size() - 1, i - 1) << endl;
  return 0;
}
