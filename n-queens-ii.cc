class Solution {
  public:
    int totalNQueens(int n) {
      int result = 0;
      vector<bool> col(n, false);
      vector<bool> diag(2 * n, false), anti_diag(2 * n, false);
      dfs(result, 0, n, col, diag, anti_diag);
      return result;
    }

    void dfs(int& result, int line, int n, vector<bool>& col, vector<bool>& diag, vector<bool>& anti_diag) {
      if (line == n) {
        result++;
        return;
      }
      for (int i = 0; i < n; i++) {
        if (col[i] || diag[line + i] || anti_diag[line - i + n])
          continue;
        col[i] = true;
        diag[line + i] = true;
        anti_diag[line - i + n] = true;
        dfs(result, line + 1, n, col, diag, anti_diag);
        col[i] = false;
        diag[line + i] = false;
        anti_diag[line - i + n] = false;
      }
    }
};
