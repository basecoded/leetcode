class Solution {
  public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
      sort(num.begin(), num.end());
      vector<vector<int>> result;
      vector<int> tmp;
      vector<bool> used(num.size(), false);
      dfs(result, tmp, num, used);
      return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& tmp, const vector<int>& num, vector<bool>& used) {
      if (tmp.size() == num.size()) {
        result.push_back(tmp);
        return;
      }
      int last = INT_MIN;
      for (int i = 0; i < num.size(); i++) {
        if (num[i] == last || used[i])
          continue;
        last = num[i];
        tmp.push_back(num[i]);
        used[i] = true;
        dfs(result, tmp, num, used);
        tmp.pop_back();
        used[i] = false;
      }
    }
};
