class Solution {
  public:
    vector<vector<string>> partition(string s) {
      int n = s.size();
      vector<vector<bool>> dp(n, vector<bool>(n, false));
      vector<vector<string>> result;
      vector<string> tmp;
      cut(dp, s);
      dfs(result, dp, tmp, s, 0);
      return result;
    }

    void cut(vector<vector<bool>>& dp, const string& s) {
      int n = s.size();
      for (int L = 0; L < s.size(); L++) {
        for (int i = 0; i + L < s.size(); i++) {
          int j = i + L;
          if (L == 0)
            dp[i][j] = true;
          else if (L == 1)
            dp[i][j] = s[i] == s[j];
          else
            dp[i][j] = (s[i] == s[j]) && (dp[i+1][j-1]);
        }
      }
    }

    void dfs(vector<vector<string>>& result, vector<vector<bool>>& dp, vector<string>& tmp, const string& s, int start) {
      if (start == s.size()) {
        result.push_back(tmp);
        return;
      }
      for (int i = start; i < s.size(); i++) {
        if (dp[start][i]) {
          tmp.push_back(s.substr(start, i - start + 1));
          dfs(result, dp, tmp, s, i + 1);
          tmp.pop_back();
        }
      }
    }
};
