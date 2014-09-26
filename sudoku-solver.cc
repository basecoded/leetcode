class Solution {
  public:
    void solveSudoku(vector<vector<char> > &board) {
      if (solve(board))
        return;
    }

    bool solve(vector<vector<char>>& board) {
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          if (board[i][j] == '.') {
            for (int val = 1; val <= 9; val++) {
              board[i][j] = '0' + val;
              if (check(board, i, j) && solve(board))
                return true;
              board[i][j] = '.';
            }
            return false;
          }
        }
      }
      return true;
    }

    bool check(const vector<vector<char>>& board, int x, int y) {
      for (int i = 0; i < 9; i++)
        if (i != x && board[i][y] == board[x][y])
          return false;
      for (int j = 0; j < 9; j++)
        if (j != y && board[x][j] == board[x][y])
          return false;
      for (int i = 3 * (x / 3); i < 3 * (x / 3) + 3; i++) {
        for (int j = 3 * (y / 3); j < 3 * (y / 3) + 3; j++) {
          if (x != i && y != j && board[i][j] == board[x][y])
            return false;
        }
      }
      return true;
    }
};
