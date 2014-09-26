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
