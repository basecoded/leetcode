class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
      stack<int> s;
      for (auto const& token : tokens) {
        if (token != "+" && token != "-" && token != "*" && token != "/") 
          s.push(stoi(token));
        else {
          int b = s.top();
          s.pop();
          int a = s.top();
          s.pop();
          s.push(calc(a, b, token[0]));
        }
      }
      return s.top();
    }

    int calc(int a, int b, char op) {
      if (op == '+')
        return a + b;
      if (op == '-')
        return a - b;
      if (op == '*')
        return a * b;
      else
        return a / b;
    }
};
