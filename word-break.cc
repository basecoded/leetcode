class Solution {
  public:
    bool wordBreak(string s, unordered_set<string> &dict) {
      int len = s.size();
      vector<vector<bool>> dp(len, vector<bool>(len + 1, false));
      dp[0][0] = true;
      for (int i = 0; i <= len; i++) {
        for (int j = i; j >= 0; j--) {
          if (dp[0][j] && dict.find(s.substr(j, i - j)) != dict.end()) {
            dp[0][i] = true;
            break;
          }
        }
      }
      return dp[0][len];
    }
};
