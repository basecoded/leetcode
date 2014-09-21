class Solution {
  public:
    string convert(string s, int nRows) {
    int n = s.size();
    vector<vector<char>> matrix(nRows, vector<char>(n, ' '));
    int index = 0;
    int col = 0;
    while(index < n) {
      for(int i = 0; i < nRows && index < n; i++)
        matrix[i][col] = s[index++];
        col++;
      for(int i = nRows - 2; i > 0 && index < n; i--)
        matrix[i][col++] = s[index++];
    }
    string result;
    for(int i = 0; i < nRows; i++)
      for(int j = 0; j < n; j++)
        if(matrix[i][j] != ' ')
          result.push_back(matrix[i][j]);
    return result;
  }
};
