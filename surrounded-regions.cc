class Solution {
  public:
    void solve(vector<vector<char>> &board) {
      if (board.size() == 0)
        return;
      const int row = board.size();
      const int col = board[0].size();
      queue<pair<int, int>> q;
      for (int i = 0; i < row; i++) {
        bfs(board, q, i, 0, row, col);
        bfs(board, q, i, col - 1, row, col);
      }
      for (int i = 0; i < col; i++) {
        bfs(board, q, 0, i, row, col);
        bfs(board, q, row - 1, i, row, col);
      }
      for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
          if (board[i][j] == '+')
            board[i][j] = 'O';
          else if (board[i][j] == 'O')
            board[i][j] = 'X';
      return;
    }

    void visit(vector<vector<char>>& board, queue<pair<int, int>>& q, 
        const int i, const int j, const int row, const int col) {
      if (i < 0 || i >= row || j < 0 || j >= col)
        return;
      if (board[i][j] == 'O') {
        q.push(make_pair(i, j));
        board[i][j] = '+';
      }
    }
    void bfs(vector<vector<char>>& board, queue<pair<int, int>>& q,
        int i, int j, const int row, const int col) {
      visit(board, q, i, j, row, col);
      while (!q.empty()) {
        int tmp_i = q.front().first;
        int tmp_j = q.front().second;
        q.pop();
        visit(board, q, tmp_i - 1, tmp_j, row, col);
        visit(board, q, tmp_i + 1, tmp_j, row, col);
        visit(board, q, tmp_i, tmp_j - 1, row, col);
        visit(board, q, tmp_i, tmp_j + 1, row, col);
      }
    }
};
