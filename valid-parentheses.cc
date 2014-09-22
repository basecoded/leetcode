class Solution {
  public:
    bool isValid(string s) {
      stack<char> stk;
      for (int i = 0; i < s.size(); i++) {
        if (stk.empty() || s[i] == '(' || s[i] == '[' || s[i] == '{') {
          stk.push(s[i]);
        } else {
          char ch = stk.top();
          stk.pop();
          if (!((ch == '(' && s[i] == ')') || (ch == '[' && s[i] == ']') || (ch == '{' && s[i] == '}')))
            return false;
        }
      }
      return stk.empty();
    }
};
