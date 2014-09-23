class Solution {
  public:
    char *strStr(char *haystack, char *needle) {
      int hay_len = strlen(haystack);
      int nee_len = strlen(needle);
      for (int i = 0; i <= hay_len - nee_len; i++) {
        char *p = haystack + i;
        char *q = needle;
        while (*q != '\0') {
          if (*p != *q)
            break;
          p++;
          q++;
        }
        if (*q == '\0')
          return haystack + i;
      }
      return NULL;
    }
};
