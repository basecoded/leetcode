class Solution {
  public:
    int trap(int A[], int n) {
      int water = 0;
      int left = 0, right = n - 1;
      int l_high = A[0], r_high = A[n-1];
      while (left < right) {
        if (l_high > r_high) {
          right--;
          water += max(0, r_high - A[right]);
          r_high = max(r_high, A[right]);
        } else {
          left++;
          water += max(0, l_high - A[left]);
          l_high = max(l_high, A[left]);
        }
      }
      return water;
    }
};
