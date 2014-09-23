int FindPeakInArray(const vector<int>& array) {
  int left = 0;
  int right = array.size() - 1;
  while (left <= right) {
    if (left == right)
      return left;
    if (right - left == 1)
      return array[left] > array[right] ? left : right;
    int mid = left + (right - left) / 2;
    if (array[mid] >= array[mid - 1] && array[mid] >= array[mid + 1])
      return mid;
    else if (array[mid] < array[mid - 1])
      right = mid - 1;
    else
      left = mid + 1;
  }
  return -1;
}

pair<int, int> FindPeak(const vector<vector<int>>& matrix) {
  int n = matrix.size();
  pair<int, int> p(-1,-1);
  int row_start = 0, row_end = n - 1;
  while (row_start < row_end) {
    int mid = row_start + (row_end - row_start) / 2;
    int i = FindPeakInArray(matrix[mid]);
    if (mid == 0) {
      if (matrix[mid + 1][i] <= matrix[mid][i])
        return make_pair(mid, i);
      else
        row_start = mid + 1;
    } else if (mid == n - 1) {
      if (matrix[mid - 1][i] <= matrix[mid][i])
        return make_pair(mid, i);
      else
        row_end = mid - 1;
    } else {
      if (matrix[mid - 1][i] <= matrix[mid][i] && matrix[mid + 1][i] <= matrix[mid][i])
        return make_pair(mid, i);
      else if (matrix[mid - 1][i] > matrix[mid][i])
        row_end = mid - 1;
      else
        row_start = mid + 1;
    }
  }
  int i = FindPeakInArray(matrix[row_start]);
  return make_pair(row_start, i);
}

/*
   {9, 3, 5, 2, 4, 9, 8};
   {7, 2, 5, 1, 4, 0, 3};
   {9, 8, 9, 3, 2, 4, 8};
   {7, 6, 3, 1, 3, 2, 3};
   {9, 0, 6, 0, 4, 6, 4};
   {8, 9, 9, 0, 5, 3, 0};
   {2, 1, 2, 1, 1, 1, 1};
 */

int main() {
  vector<int> v { 9, 3, 5, 2, 4, 9, 8 };
  vector<int> v1 { 7, 2, 5, 1, 4, 0, 3 };
  vector<int> v2 { 9, 8, 9, 3, 2, 4, 8 };
  vector<int> v3 { 7, 6, 3, 1, 3, 2, 3 };
  vector<int> v4 { 9, 0, 6, 0, 4, 6, 4 };
  vector<int> v5 { 8, 9, 8, 0, 5, 3, 0 };
  vector<int> v6 { 2, 1, 2, 1, 1, 1, 1 };
  vector<vector<int>> matrix;
  matrix.push_back(v);
  matrix.push_back(v1);
  matrix.push_back(v2);
  matrix.push_back(v3);
  matrix.push_back(v4);
  matrix.push_back(v5);
  matrix.push_back(v6);
  pair<int, int> p = FindPeak(matrix);
  cout << p.first << " " << p.second << endl;
  return 0;
}
