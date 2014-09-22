class Solution {
  public:
    bool canJump(int A[], int n) {
      if (n == 1)
        return true;
      int max_len = A[0];
      for (int i = 1; i <= max_len; i++) {
        max_len = max(max_len, i + A[i]);
        if (max_len >= n - 1)
          return true;
      }
      return false;
    }
};
