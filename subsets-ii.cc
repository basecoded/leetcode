class Solution {
  public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
      sort(S.begin(), S.end());
      vector<vector<int>> result;
      for (int i = 0; i <= S.size(); i++) {
        vector<int> tmp;
        dfs(result, tmp, S, 0, i);
      }
      return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& tmp, vector<int>& S, int start, int number) {
      if (tmp.size() == number) {
        result.push_back(tmp);
        return;
      }
      for (int i = start; i < S.size(); i++) {
        if (i > start && S[i] == S[i-1])
          continue;
        tmp.push_back(S[i]);
        dfs(result, tmp, S, i + 1, number);
        tmp.pop_back();
      }
    }
};
