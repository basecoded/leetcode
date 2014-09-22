class Solution {
  public:
    int maxSubArray(int A[], int n) {
      if (n == 0)
        return 0;
      vector<int> sum(n);
      sum[0] = A[0];
      int max_sum = A[0];
      for (int i = 1; i < n; i++) {
        if (sum[i-1] > 0)
          sum[i] = sum[i-1] + A[i];
        else
          sum[i] = A[i];
        max_sum = max(max_sum, sum[i]);
      }
      return max_sum;
    }
};
