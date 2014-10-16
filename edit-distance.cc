class Solution {
  public:
    int minDistance(string word1, string word2) {
      // IMPORTANT: Please reset any member data you declared, as
      // the same Solution instance will be reused for each test case.
      const int col = word1.size();
      const int row = word2.size();
      vector<vector<int>> result(row + 1, vector<int>(col + 1));
      for (int i = 0; i <= col; i++) {
        result[0][i] = i;
      }
      for (int i = 0; i <= row; i++) {
        result[i][0] = i;
      }
      for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
          if (word2[i - 1] == word1[j - 1])
            result[i][j] = result[i - 1][j - 1];
          else {
            result[i][j] = min(result[i - 1][j - 1], result[i][j - 1]);
            result[i][j] = min(result[i][j], result[i - 1][j]) + 1;
          }
        }
      }
      return result[row][col];
    }
};

// O(n) space optimization
class Solution {
  public:
    int minDistance(string word1, string word2) {
      int len1 = word1.size();
      int len2 = word2.size();
      vector<int> f(len2 + 1, 0);
      for (int i = 0; i <= len2; i++)
        f[i] = i;
      int upper_left = 0; // to remember f[i-1][j-1]
      for (int i = 1; i <= len1; i++) {
        upper_left = f[0];
        f[0] = i;
        for (int j = 1; j <= len2; j++) {
          int upper = f[j];
          if (word1[i-1] == word2[j-1])
            f[j] = upper_left;
          else
            f[j] = min(upper_left, min(f[j], f[j-1])) + 1;
          upper_left = upper;
        }
      }
      return f[len2];
    }
};
