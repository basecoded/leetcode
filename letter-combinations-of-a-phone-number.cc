class Solution {
  public:
    const vector<string> keyboard {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
      vector<string> result;
      string str;
      dfs(result, str, 0, digits);
      return result;
    }

    void dfs(vector<string>& result, string tmp, int start, const string& digits) {
      if (start == digits.size()) {
        result.push_back(tmp);
        return;
      }
      string letters = keyboard[digits[start] - '0'];
      for (int i = 0; i < letters.size(); i++)
        dfs(result, tmp + letters[i], start + 1, digits);
    }
};
