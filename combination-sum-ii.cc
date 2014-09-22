class Solution {
  public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
      sort(num.begin(), num.end());
      vector<vector<int>> result;
      vector<int> tmp;
      dfs(result, num, tmp, 0, target);
      return result;
    }

    void dfs(vector<vector<int>>& result, const vector<int>& num, vector<int>& tmp, int start, int gap) {
      if (gap == 0) {
        result.push_back(tmp);
        return;
      }
      for (int i = start; i < num.size(); i++) {
        if (num[i] > gap)
          return;
        if (i > start && num[i] == num[i-1])
          continue;
        tmp.push_back(num[i]);
        dfs(result, num, tmp, i + 1, gap - num[i]);
        tmp.pop_back();
      }
    }
};
