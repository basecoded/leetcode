#include <iostream>
#include <vector>

using namespace std;

int GetNoConsecutiveCharString(const string& str) {
  int n = str.size();
  vector<int> number(n);
  number[n-1] = 1;
  for (int i = n - 2; i >= 0; i--)
    number[i] = number[i+1] * 25;
  int result = str[0] == 'a' ? 0 : (str[0] - 'a') * number[0];
  for (int i = 1; i < str.size(); i++) {
    for (int ch = 'a'; ch < str[i]; ch++) {
      if (ch != str[i-1])
        result += number[i];
    }
  }
  if (n == 1 || (n > 1 && str[n-1] != str[n-2]))
    result++;
  return result;
}

int main() {
  cout << GetNoConsecutiveCharString("a") << endl;
  return 0;
}
