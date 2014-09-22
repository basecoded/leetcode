class Solution {
  public:
    string countAndSay(int n) {
      string result = "1";
      for (int i = 1; i < n; i++)
        result = next(result);
      return result;
    }

    string next(const string& str) {
      string result;
      int count = 0;
      for (int i = 0; i < str.size(); i++) {
        if (i == 0 || str[i] == str[i-1])
          count++;
        else {
          result.append(to_string(count) + "" + str[i-1]);
          count = 1;
        }
      }
      result.append(to_string(count) + str[str.size() - 1]);
      return result;
    }
};
