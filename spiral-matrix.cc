class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
      vector<int> result;
      if (matrix.size() == 0)
        return result;
      int row_start = 0, row_end = matrix.size() - 1;
      int col_start = 0, col_end = matrix[0].size() - 1;
      while (row_start <= row_end && col_start <= col_end) {
        for (int i = col_start; i <= col_end; i++)
          result.push_back(matrix[row_start][i]);
        if (++row_start > row_end)
          break;
        for (int i = row_start; i <= row_end; i++)
          result.push_back(matrix[i][col_end]);
        if (--col_end < col_start)
          break;
        for (int i = col_end; i >= col_start; i--)
          result.push_back(matrix[row_end][i]);
        if (--row_end < row_start)
          break;
        for (int i = row_end; i >= row_start; i--)
          result.push_back(matrix[i][col_start]);
        if (++col_start > col_end)
          break;
      }
      return result;
    }
};
