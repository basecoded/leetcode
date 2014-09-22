class Solution {
  public:
    string addBinary(string a, string b) {
      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
      string result;
      int carry = 0;
      int i = 0;
      while (i < a.size() || i < b.size()) {
        int val1 = i < a.size() ? a[i] - '0' : 0;
        int val2 = i < b.size() ? b[i] - '0' : 0;
        int sum = val1 + val2 + carry;
        carry = sum / 2;
        sum %= 2;
        result.push_back(sum + '0');
        i++;
      }
      if (carry)
        result.push_back('1');
      reverse(result.begin(), result.end());
      return result;
    }
};
