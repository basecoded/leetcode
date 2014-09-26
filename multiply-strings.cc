class Solution {
  public:
    string multiply(string num1, string num2) {
      reverse(num1.begin(), num1.end());
      reverse(num2.begin(), num2.end());
      int len1 = num1.size(), len2 = num2.size();
      vector<int> result(len1 + len2, 0);
      for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
          int val1 = num1[i] - '0';
          int val2 = num2[j] - '0';
          result[i+j] += (val1 * val2);
          result[i+j+1] += result[i+j] / 10;
          result[i+j] %= 10;
        }
      }
      int i = result.size() - 1;
      for (; i >= 0; i--)
        if (result[i] != 0)
          break;
      if (i == -1)
        return "0";
      string str;
      for (; i >= 0; i--)
        str.append(to_string(result[i]));
      return str;
    }
};
