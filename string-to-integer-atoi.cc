class Solution {
  public:
    int atoi(const char *str) {
      bool sign = true;
      while (*str == ' ')
        str++;
      if (*str == '-') {
        sign = false;
        str++;
      } else if (*str == '+') {
        str++;
      }
      long long result = 0;
      for (; *str != '\0'; str++) {
        if (*str >= '0' && *str <= '9') {
          result = result * 10 + *str - '0';
          if (sign && result >= INT_MAX)
            return INT_MAX;
          else if (!sign && -result <= INT_MIN)
            return INT_MIN;
        }
        else {
          return sign ? result : -result;
        }
      }
      return sign ? result : -result;
    }
};
