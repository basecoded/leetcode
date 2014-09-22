class Solution {
  public:
    int removeDuplicates(int A[], int n) {
      int idx = 0;
      for (int i = 0; i < n; i++) {
        if (i == 0 || A[i] != A[i - 1])
          A[idx++] = A[i];
      }
      return idx;
    }
};
