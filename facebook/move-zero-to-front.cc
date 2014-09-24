#include <iostream>
#include <vector>

using namespace std;

void MoveZeroToFront(vector<int>& num) {
  int idx = num.size() - 1;
  int count = 0;
  for (int i = num.size() - 1; i >= 0; i--) {
    if (num[i] == 0)
      count++;
    else
      num[idx--] = num[i];
  }
  for (int i = 0; i < count; i++)
    num[i] = 0;
  return;
}

int main() {
  vector<int> v{1,0,2,3,0,0,4,5,0,0};
  MoveZeroToFront(v);
  for (const auto a : v)
    cout << a << " ";
  cout << endl;
  return 0;
}
