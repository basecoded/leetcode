class Solution {
  public:
    vector<string> generateParenthesis(int n) {
      vector<string> result;
      Generate(result, "", 0, 0, n);
      return result;
    }

    void Generate(vector<string>& result, string s, int left, int right, int n) {
      if (right == n) {
        result.push_back(s);
        return;
      }
      if (right < left)
        Generate(result, s + ")", left, right + 1, n);
      if (left < n)
        Generate(result, s + "(", left + 1, right, n);
    }
};
