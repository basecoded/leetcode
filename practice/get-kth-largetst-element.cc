#include <iostream>
#include <vector>

int Partition(vector<int>& v, int low, int high) {
  int start = low;
  int pivot = v[low];
  while (low < high) {
    while (low < v.size() && v[low] >= pivot)
      low++;
    while (high >= 0 && v[high] < pivot)
      high--;
    if (low < high)
      swap(v[low], v[high]);
  }
  swap(v[start], v[high]);
  return high;
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
  int k = 5;
  cout << FindKthLarge(v, 0, v.size() - 1, k - 1) << endl;
  return 0;
}
