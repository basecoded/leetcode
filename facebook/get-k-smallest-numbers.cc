#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int>& num, int start, int end) {
  int pivot = num[start];
  int origin_start = start;
  while (start < end) {
    if (start < num.size() && num[start] <= pivot)
      start++;
    else if (end >= 0 && num[end] > pivot)
      end--;
    if (start < end)
      swap(num[start], num[end]);
  }
  swap(num[origin_start], num[end]);
  return end;
}

int GetKSmallestElements(vector<int>& num, int k, int start, int end) {
  if (start >= end)
    return num[start];
  int idx = Partition(num, start, end);
  if (idx > k)
    return GetKSmallestElements(num, k, start, idx - 1);
  else if (idx < k)
    return GetKSmallestElements(num, k, idx + 1, end);
  else
    return num[idx];
}

int GetKSmallestElements(vector<int>& num, int k) {
  return GetKSmallestElements(num, k - 1, 0, num.size() - 1);
}

int main() {
  vector<int> v{1, 2, 5, 4, 3};
  int k = 3;
  cout << GetKSmallestElements(v, k, 0, v.size() - 1) << endl;
  return 0;
}
