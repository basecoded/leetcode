class Solution {
  public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
      if (matrix.size() == 0)
        return false;
      int row = matrix.size();
      int col = matrix[0].size();
      if (target < matrix[0][0] || target > matrix[row - 1][col - 1])
        return false;
      for (int i = 0; i < row; i++) {
        if (matrix[i][col - 1] >= target)
          return binary_search(matrix[i], target);
      }
      return false;
    }

    bool binary_search(const vector<int>& v, int target) {
      int start = 0, end = v.size() - 1;
      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (v[mid] == target)
          return true;
        else if (v[mid] < target)
          start = mid + 1;
        else
          end = mid - 1;
      }
      return false;
    }
};
