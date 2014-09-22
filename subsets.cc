class Solution {
  public:
    vector<vector<int> > subsets(vector<int> &S) {
      sort(S.begin(), S.end());
      vector<vector<int>> result;
      int n = S.size();
      for (int i = 0; i < (1 << n); i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
          if ((i >> j) & 1)
            tmp.push_back(S[j]);
        }
        result.push_back(tmp);
      }
      return result;
    }
};
