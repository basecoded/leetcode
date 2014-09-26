class Solution {
  public:
    int maxProduct(int A[], int n) {
      if (n == 0)
        return 0;
      vector<int> max_v(n), min_v(n);
      max_v[0] = min_v[0] = A[0];
      int value = A[0];
      for (int i = 1; i < n; i++) {
        max_v[i] = max(A[i], max(max_v[i - 1] * A[i], min_v[i - 1] * A[i]));
        min_v[i] = min(A[i], min(max_v[i - 1] * A[i], min_v[i - 1] * A[i]));
        value = max(value, max_v[i]);
      }
      return value;
    }
};
