class Solution {
  public:
    bool isScramble(string s1, string s2) {
      if (s1.size() != s2.size())
        return false;
      string tmp1 = s1, tmp2 = s2;
      sort(tmp1.begin(), tmp1.end());
      sort(tmp2.begin(), tmp2.end());
      if (tmp1 != tmp2)
        return false;
      int n = s1.size();
      if (n == 1)
        return s1 == s2;
      for (int i = 1; i < n; i++) {
        if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i)))
            || (isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i))))
          return true;
      }
      return false;
    }
};
