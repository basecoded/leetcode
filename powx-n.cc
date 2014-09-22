class Solution {
  public:
    double pow(double x, int n) {
      if (n < 0) {
        if (n == INT_MIN)
          return 1 / (pow(x, -(n+1)) * x);
        else
          return 1 / pow(x, -n);
      }
      if (n == 0)
        return 1;
      double y = pow(x, n / 2);
      if (n % 2)
        return y * y * x;
      else
        return y * y;
    }
};
