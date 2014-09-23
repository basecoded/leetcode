#include <iostream>
#include <vector>

using namespace std;

int LostElementInArray(const vector<int>& v) {
  if (v.size() < 3)
    return 0;
  int diff = min(v[1] - v[0], v[2] - v[1]);
  int start = 0, end = v.size() - 1;
  while (start < end) {
    if (end - start == 1)
      return (v[start] + v[end]) / 2;
    int mid = start + (end - start) / 2;
    int expected = v[start] + diff * (mid - start);
    if (v[mid] == expected)
      start = mid;
    else
      end = mid;
  }
  return -1;
}

int main() {
  vector<int> v{1, 3, 7, 9, 11, 13};
  cout << LostElementInArray(v) << endl;
  return 0;
}
