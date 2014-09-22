class Solution {
  public:
    inline int map(const char c) {
      switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
      }
    }
    int romanToInt(string s) {
      int result = 0;
      for (int i = 0; i < s.size(); i++) {
        result += map(s[i]);
        if (i > 0 && map(s[i]) > map(s[i-1]))
          result -= 2 * map(s[i-1]);
      }
      return result;
    }
};
