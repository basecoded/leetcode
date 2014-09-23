class Solution {
  public:
    int minCut(string s) {
      int n = s.size();
      vector<vector<bool>> dp(n, vector<bool>(n, false));
      for (int L = 0; L < s.size(); L++) {
        for (int i = 0; i + L < s.size(); i++) {
          int j = i + L;
          if (L == 0)
            dp[i][j] = true;
          else if (L == 1)
            dp[i][j] = s[i] == s[j];
          else
            dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
        }
      }
      vector<int> cut(n + 1, INT_MAX);
      cut[0] = 0;
      for (int j = 0; j < n; j++) {
        for (int i = j; i >= 0; i--) {
          if (dp[i][j])
            cut[j + 1] = min(cut[j + 1], cut[i] + 1);
        }
      }
      return cut[n] - 1;
    }
};
