class Solution {
  public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
      sort(candidates.begin(), candidates.end());
      vector<vector<int>> result;
      vector<int> tmp;
      dfs(result, tmp, candidates, 0, target);
      return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& tmp,
        vector<int>& candidates, int start, int gap) {
      if (gap == 0) {
        result.push_back(tmp);
        return;
      }
      for (int i = start; i < candidates.size(); i++) {
        if (candidates[i] > gap)
          return;
        tmp.push_back(candidates[i]);
        dfs(result, tmp, candidates, i, gap - candidates[i]);
        tmp.pop_back();
      }
    }
};
