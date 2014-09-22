class Solution {
  public:
    bool isValidSudoku(vector<vector<char> > &board) {
      for (int i = 0; i < 9; i++) {
        vector<bool> used(9, false);
        for (int j = 0; j < 9; j++) {
          if (board[i][j] != '.') {
            if (used[board[i][j] - '1'])
              return false;
            used[board[i][j] - '1'] = true;
          }
        }
      }
      for (int i = 0; i < 9; i++) {
        vector<bool> used(9, false);
        for (int j = 0; j < 9; j++) {
          if (board[j][i] != '.') {
            if (used[board[j][i] - '1'])
              return false;
            used[board[j][i] - '1'] = true;
          }
        }
      }
      for (int m = 0; m < 3; m++) {
        for (int n = 0; n < 3; n++) {
          vector<bool> used(9, false);
          for (int i = 3 * m; i < 3 * m + 3; i++) {
            for (int j = 3 * n; j < 3 * n + 3; j++) {
              if (board[i][j] != '.') {
                if (used[board[i][j] - '1'])
                  return false;
                used[board[i][j] - '1'] = true;
              }
            }
          }
        }
      }
      return true;
    }
};
