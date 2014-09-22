class Solution {
  public:
    vector<vector<int> > generateMatrix(int n) {
      int start = 0, end = n - 1;
      vector<vector<int>> matrix(n, vector<int>(n));
      int num = 1;
      while (start < end) {
        for (int j = start; j < end; j++)
          matrix[start][j] = num++;
        for (int i = start; i < end; i++)
          matrix[i][end] = num++;
        for (int j = end; j > start; j--)
          matrix[end][j] = num++;
        for (int i = end; i > start; i--)
          matrix[i][start] = num++;
        start++;
        end--;
      }
      if (n % 2)
        matrix[n/2][n/2] = num;
      return matrix;
    }
};
