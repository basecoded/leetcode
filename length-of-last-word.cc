class Solution {
  public:
    int lengthOfLastWord(const char *s) {
      int len = 0, last_len = 0;
      while (*s) {
        if (*s != ' ') {
          ++len;
        } else {
          if (len != 0)
            last_len = len;
          len = 0;
        }
        s++;
      }
      return len == 0 ? last_len : len;
    }
};
