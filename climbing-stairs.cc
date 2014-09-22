class Solution {
  public:
    int climbStairs(int n) {
      if (n < 3)
        return n;
      int one = 1;
      int two = 2;
      int result = 0;
      for (int i = 3; i <= n; i++) {
        result = one + two;
        one = two;
        two = result;
      }
      return result;
    }
};
