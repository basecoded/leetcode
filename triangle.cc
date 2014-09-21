class Solution {
  public:
    int minimumTotal(vector<vector<int> > &triangle) {
      int row = triangle.size();
      if (row == 0)
        return 0;
      for (int i = 1; i < row; i++) {
        for (int j = 0; j <= i; j++) {
          if (j == 0)
            triangle[i][j] += triangle[i-1][j];
          else if (j == i)
            triangle[i][j] += triangle[i-1][j-1];
          else
            triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
        }
      }
      int min_sum = INT_MAX;
      for (int i = 0; i < row; i++) {
        min_sum = min(min_sum, triangle[row - 1][i]);
      }
      return min_sum;
    }
};
