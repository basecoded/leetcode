class Solution {
  public:
    void merge(int A[], int m, int B[], int n) {
      int i = m - 1, j = n - 1, k = m + n - 1;
      while (i >= 0 || j >= 0) {
        int val1 = i >= 0 ? A[i] : INT_MIN;
        int val2 = j >= 0 ? B[j] : INT_MIN;
        if (val1 > val2)
          A[k--] = A[i--];
        else
          A[k--] = B[j--];
      }
      return;
    }
};
