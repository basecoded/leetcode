class Solution {
  public:
    string longestPalindrome(string s) {
      const int n = s.size();
      bool f[n][n];
      fill_n(&f[0][0], n * n, false);
      int start = 0;
      int max_len = 0;
      for(int L = 0; L < s.size(); L++) {
        for(int i = 0; i + L < s.size(); i++) {
          int j = i + L;
          if(L == 0)
            f[i][j] = true;
          else if(L == 1)
            f[i][j] = s[i] == s[j];
          else
            f[i][j] = f[i+1][j-1] && (s[i] == s[j]);
          if(f[i][j] && j - i + 1 > max_len) {
            max_len = j - i + 1;
            start = i;
          }
        }
      }
      return s.substr(start, max_len);
    }
};
