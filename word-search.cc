class Solution {
  public:
    bool exist(vector<vector<char> > &board, string word) {
      const int row = board.size();
      const int col = board[0].size();
      vector<vector<bool>> visited(row, vector<bool>(col, false));
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          if (dfs(board, i, j, word, 0, visited))
            return true;
        }
      }
      return false;
    }

    bool dfs(const vector<vector<char>>& board, int i, int j, const string& word, int start, vector<vector<bool>>& visited) {
      if (start == word.size())
        return true;
      if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0)
        return false;
      if (visited[i][j] || board[i][j] != word[start])
        return false;
      visited[i][j] = true;
      bool result = dfs(board, i - 1, j, word, start + 1, visited)
        || dfs(board, i + 1, j, word, start + 1, visited)
        || dfs(board, i, j - 1, word, start + 1, visited)
        || dfs(board, i, j + 1, word, start + 1, visited);
      visited[i][j] = false;
      return result;
    }
};
