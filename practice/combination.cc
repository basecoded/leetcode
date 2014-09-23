#include <iostream>
#include <vector>

using namespace std;

//This function is to print all the combinations of an integer n.
//n = 4, {1, 1, 1, 1}, {1, 1, 2}. {2, 2}, {1, 3}
int combination(int n) {
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  for (int i = 1; i < n; i++) { // scores
    for (int j = i; j <= n; j++) { // total sum
      if (j - i >= 0)
        dp[j] += dp[j-i];
    }
  }
  return dp[n];
}

int main() {
  cout << combination(4) << endl;
  return 0;
}
