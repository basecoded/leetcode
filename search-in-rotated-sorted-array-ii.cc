class Solution {
  public:
    bool search(int A[], int n, int target) {
      int start = 0, end = n - 1;
      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (A[mid] == target)
          return true;
        if (A[start] == A[mid])
          start++;
        else if (A[start] < A[mid]) {
          if (A[start] <= target && target < A[mid])
            end = mid - 1;
          else
            start = mid + 1;
        } else {
          if (A[mid] < target && target <= A[end])
            start = mid + 1;
          else
            end = mid - 1;
        }
      }
      return false;
    }
};
