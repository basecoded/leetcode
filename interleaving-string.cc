class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
      int len1 = s1.size();
      int len2 = s2.size();
      int len3 = s3.size();
      if (len1 + len2 != len3)
        return false;
      vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
      for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
          if (i == 0 && j == 0)
            dp[0][0] = true;
          if (i > 0 && s3[i + j - 1] == s1[i-1])
            dp[i][j] = dp[i][j] | dp[i-1][j];
          if (j > 0 && s3[i + j - 1] == s2[j-1])
            dp[i][j] = dp[i][j] | dp[i][j-1];
        }
      }
      return dp[len1][len2];
    }
};
