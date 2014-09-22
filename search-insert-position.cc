class Solution {
  public:
    int searchInsert(int A[], int n, int target) {
      if (target < A[0])
        return 0;
      if (target > A[n-1])
        return n;
      int start = 0, end = n - 1;
      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (target == A[mid])
          return mid;
        else if (target > A[mid])
          start = mid + 1;
        else
          end = mid - 1;
      }
      return start;
    }
};
