class Solution {
  public:
    vector<int> searchRange(int A[], int n, int target) {
      int left = 0, right = n - 1;
      int min_idx = INT_MAX, max_idx = INT_MIN;
      binary_search(A, 0, n - 1, min_idx, max_idx, target);
      if (min_idx == INT_MAX && max_idx == INT_MIN)
        return vector<int>(2, -1);
      else {
        vector<int> result(2);
        result[0] = min_idx;
        result[1] = max_idx;
        return result;
      }
    }

    void binary_search(int A[], int start, int end, int &min_idx, int &max_idx, int target) {
      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (A[mid] == target) {
          min_idx = min(min_idx, mid);
          max_idx = max(max_idx, mid);
          binary_search(A, mid + 1, end, min_idx, max_idx, target);
          binary_search(A, start, mid - 1, min_idx, max_idx, target);
          return;
        }
        else if (A[mid] < target) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }
    }
};
