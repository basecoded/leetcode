class Solution {
  public:
    int reverse(int x) {
      bool is_negative = false;
      if (x < 0) {
        is_negative = true;
        x = -x;
      }
      int result = 0;
      while (x) {
        result = result * 10 + (x%10);
        x /= 10;
      }
      return is_negative ? -result : result;
    }
};
