class Solution {
  public:
    vector<vector<int> > generate(int numRows) {
      vector<vector<int>> result;
      for (int i = 0; i < numRows; i++) {
        vector<int> tmp(i + 1, 1);
        result.push_back(tmp);
        for (int j = 0; j <= i; j++) {
          if (j == 0 || j == i)
            result[i][j] = 1;
          else if (i > 0)
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
      }
      return result;
    }
};
