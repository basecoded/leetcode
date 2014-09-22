class Solution {
  public:
    int jump(int A[], int n) {
      if (n <= 1)
        return 0;
      int left = 0, right = 0;
      int step = 0;
      while (left <= right) {
        step++;
        int new_right = right;
        for (int i = left; i <= right; i++) {
          int tmp = i + A[i];
          if (tmp >= n - 1)
            return step;
          new_right = max(new_right, tmp);
        }
        right = new_right;
      }
      return -1;
    }
};
