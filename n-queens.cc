class Solution {
  public:
    vector<vector<string> > solveNQueens(int n) {
      vector<int> position;
      vector<bool> vertical(n);
      vector<bool> diag(2 * n, false);
      vector<bool> anti_diag(2 * n, false);
      vector<vector<string>> result;
      dfs(result, 0, vertical, diag, anti_diag, position, n);
      return result;
    }

    void dfs(vector<vector<string>>& result, int line, vector<bool>& vertical, vector<bool>& diag, vector<bool>& anti_diag, vector<int>& position, int n) {
      if(line == n) {
        vector<string> tmp;
        for(int i = 0; i < position.size(); i++) {
          string str(n, '.');
          str[position[i]] = 'Q';
          tmp.push_back(str);
        }
        result.push_back(tmp);
        return;
      }
      for(int i = 0; i < n; i++) {
        if(vertical[i] == false && diag[line + i] == false && anti_diag[line - i + n] == false) {
          vertical[i] = true;
          diag[line + i] = true;
          anti_diag[line - i + n] = true;
          position.push_back(i);
          dfs(result, line + 1, vertical, diag, anti_diag, position, n);
          vertical[i] = false;
          diag[line + i] = false;
          anti_diag[line - i + n] = false;
          position.pop_back();
        }
      }
    }
};
