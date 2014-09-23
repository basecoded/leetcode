#include <iostream>
#include <vector>

using namespace std;

bool dfs(const vector<vector<char>>& board, int i, int j, const string& word,
         int start, vector<vector<bool>>& visited, vector<pair<int, int>>& path) {
  if (start == word.size()) {
    for (const auto pos : path)
      cout << pos.first << " " << pos.second << endl;
    return true;
  }
  if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0)
    return false;
  if (visited[i][j] || board[i][j] != word[start])
    return false;
  visited[i][j] = true;
  path.push_back(make_pair(i, j));
  bool result = dfs(board, i - 1, j, word, start + 1, visited, path)
    || dfs(board, i + 1, j, word, start + 1, visited, path)
    || dfs(board, i, j - 1, word, start + 1, visited, path)
    || dfs(board, i, j + 1, word, start + 1, visited, path);
  visited[i][j] = false;
  path.pop_back();
  return result;
}

bool exist(vector<vector<char> > &board, string word) {
  const int row = board.size();
  const int col = board[0].size();
  vector<vector<bool>> visited(row, vector<bool>(col, false));
  vector<pair<int, int>> path;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (dfs(board, i, j, word, 0, visited, path))
        return true;
    }
  }
  return false;
}

int main() {
  vector<char> v1{'A', 'B', 'C', 'E'};
  vector<char> v2{'S', 'F', 'C', 'S'};
  vector<char> v3{'A', 'D', 'E', 'E'};
  vector<vector<char>> matrix;
  matrix.push_back(v1);
  matrix.push_back(v2);
  matrix.push_back(v3);
  exist(matrix, "SEE");
  return 0;
}
