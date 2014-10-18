class Solution {
  public:
    vector<vector<int> > permute(vector<int> &num) {
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
      for (int i = 0; i < num.size(); i++) {
        if (used[i])
          continue;
        used[i] = true;
        tmp.push_back(num[i]);
        dfs(result, tmp, num, used);
        used[i] = false;
        tmp.pop_back();
      }
    }
};

class Solution {
  public:
    vector<vector<int> > permute(vector<int> &num) {
      vector<vector<int>> result;
      genPermute(result, 0, num);
      return result;
    }

    void genPermute(vector<vector<int>>& result, int layer, vector<int>& num) {
      if (layer == num.size()) {
        result.push_back(num);
        return;
      }
      for (int i = layer; i < num.size(); i++) {
        swap(num[i], num[layer]);
        genPermute(result, layer + 1, num);
        swap(num[i], num[layer]);
      }
    }
};
