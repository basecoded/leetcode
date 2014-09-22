class Solution {
  public:
    int getBit(int x) {
      int i = 0;
      while (x) {
        i++;
        x /= 10;
      }
      return i;
    }

    bool isPalindrome(int x) {
      if (x < 0)
        return false;
      if (x < 10)
        return true;
      int bit = getBit(x);
      while (x) {
        int first = x / pow(10, bit - 1);
        int base = x % 10;
        if (first != base)
          return false;
        x %= (int)pow(10, bit - 1);
        x /= 10;
        bit -= 2;
      }
      return true;
    }
};
