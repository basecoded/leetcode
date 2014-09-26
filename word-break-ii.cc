class Solution {
  public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
      vector<bool> f(s.size() + 1, false);
      vector<vector<bool>> pre(s.size() + 1, vector<bool>(s.size()));
      f[0] = true;
      for(int i = 1; i <= s.size(); i++) {
        for(int j = i - 1; j >= 0; j--) {
          if(f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
            f[i] = true;
            pre[i][j] = true;
          }
        }
      }
      vector<string> result;
      vector<string> path;
      gen_path(s, pre, s.size(), path, result);
      return result;
    }

    void gen_path(const string& s, const vector<vector<bool>>& pre, int cur, vector<string>& path, vector<string>& result) {
      if(cur == 0) {
        string tmp;
        for(int i = path.size() - 1; i >= 0; i--)
          tmp+=path[i] + " ";
        tmp = tmp.substr(0, tmp.size() - 1);
        result.push_back(tmp);
      } else {
        for(int i = 0; i < s.size(); i++) {
          if(pre[cur][i]) {
            path.push_back(s.substr(i, cur - i));
            gen_path(s, pre, i, path, result);
            path.pop_back();
          }
        }
      }
    }
};
