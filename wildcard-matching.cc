class Solution {
  public:
    bool isMatch(const char *s, const char *p) {
      const char* star = NULL;
      const char* rs = NULL;
      while(*s != '\0') {
        if(*s == *p || *p == '?') {
          s++;
          p++;
          continue;
        }
        if(*p == '*') {
          star = p;
          rs = s;
          p++;
          continue;
        }
        if(star != NULL) {
          p = star + 1;
          s = rs;
          rs++;
          continue;
        }
        return false;
      }
      while(*p == '*')
        p++;
      return *p == '\0';
    }
};
