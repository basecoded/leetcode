class Solution {
  public:
    int divide(int dividend, int divisor) {
      long long a = dividend >= 0 ? dividend : -(long long)dividend;
      long long b = divisor >= 0 ? divisor : -(long long)divisor;
      long long result = 0;
      while(a >= b) {
        long long c = b;
        for(int i = 0; a >= c; i++, c <<= 1) {
          result += (1 << i);
          a -= c;
        }
      }
      bool is_negative = (dividend^divisor) >> 31;
      if ((!is_negative && result > INT_MAX) || (is_negative && -result < INT_MIN))
        return INT_MAX;
      return is_negative ? (-result) : result;
    }
};
