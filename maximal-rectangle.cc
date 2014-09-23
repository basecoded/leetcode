class Solution {
  public:
    int maximalRectangle(vector<vector<char> > &matrix) {
      if (matrix.size() == 0)
        return 0;
      int row = matrix.size(), col = matrix[0].size();
      vector<vector<int>> dp(row, vector<int>(col));
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          if (i > 0 && matrix[i][j] == '1')
            dp[i][j] = dp[i-1][j] + 1;
          else
            dp[i][j] = matrix[i][j] - '0';
        }
      }
      int max_area = 0;
      for (int i = 0; i < row; i++) {
        int area = MaxAreaInALine(dp[i]);
        max_area = max(max_area, area);
      }
      return max_area;
    }

    int MaxAreaInALine(vector<int> line) {
      line.push_back(0);
      stack<int> stk;
      int max_area = 0;
      for (int i = 0; i < line.size();) {
        if (stk.empty() || line[i] > line[stk.top()]) {
          stk.push(i++);
        } else {
          int tmp = stk.top();
          stk.pop();
          int area = line[tmp] * (stk.empty() ? i : i - stk.top() - 1);
          max_area = max(max_area, area);
        }
      }
      return max_area;
    }
};
