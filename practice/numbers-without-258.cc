int getBit(int n) {
  int i = 0;
  while (n) {
    i++;
    n /= 10;
  }
  return i;
}

int NumbersWithout258(int number) {
  int bit = getBit(number);
  vector<vector<int>> dp(bit + 1, vector<int>(10, 0));
  for (int i = 1; i < 10; i++) {
    dp[1][i] = dp[1][i - 1];
    if (i != 2 && i != 5 && i != 8)
      dp[1][i]++;
  }
  for (int i = 2; i <= bit; i++) {
    for (int j = 1; j < 10; j++) {
      dp[i][j] = dp[i][j - 1];
      if (j - 1 != 2 && j - 1 != 5 && j - 1 != 8) {
        for (int k = i - 1; k > 0; k--) {
          dp[i][j] += dp[k][9];
        }
      }
      if (j != 2 && j != 5 && j != 8)
        dp[i][j]++;
    }
  }
  int result = 0;
  int i = 1;
  while (number > 0) {
    result += dp[i][number % 10];
    i++;
    number /= 10;
  }
  return result;
}

bool check(int number) {
  while (number) {
    int i = number % 10;
    if (i == 2 || i == 5 || i == 8)
      return false;
    number /= 10;
  }
  return true;
}

int BruteForce(int number) {
  int result = 0;
  for (int i = 1; i <= number; i++) {
    if (check(i))
      result++;
  }
  return result;
}

int main() {
  int i = 999;
  cout << NumbersWithout258(i) << endl;
  cout << BruteForce(i) << endl;
  return 0;
}
