class Solution {
  public:
    vector<string> restoreIpAddresses(string s) {
      vector<string> result;
      vector<int> tmp;
      dfs(result, tmp, s, 0);
      return result;
    }

    void dfs(vector<string>& result, vector<int>& tmp, const string& s, const int start) {
      if (tmp.size() == 4) {
        if (start != s.size())
          return;
        string ip = to_string(tmp[0]) + "." + to_string(tmp[1]) + "." + to_string(tmp[2]) + "." + to_string(tmp[3]);
        result.push_back(ip);
        return;
      }

      for (int i = 1; i <= 3 && i + start <= s.size(); i++) {
        int val = stoi(s.substr(start, i));
        if (val <= 255) {
          tmp.push_back(val);
          dfs(result, tmp, s, start + i);
          tmp.pop_back();
          if (val == 0)
            return;
        }
      }
    }
};
