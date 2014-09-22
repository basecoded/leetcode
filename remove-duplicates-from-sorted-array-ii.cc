class Solution {
  public:
    int removeDuplicates(int A[], int n) {
      if (n < 3)
        return n;
      int idx = 2;
      for (int i = 2; i < n; i++) {
        if (A[i] != A[idx - 2]) {
          A[idx++] = A[i];
        }
      }
      return idx;
    }
};
