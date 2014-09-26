class Solution {
  public:
    void reverseWords(string &s) {
      int start = 0;
      int end = s.size() - 1;
      while (s[start] == ' ')
        start++;
      while (s[end] == ' ')
        end--;
      s = s.substr(start, end - start + 1);
      start = 0;
      string result;
      while (start < s.size()) {
        while (s[start] == ' ')
          start++;
        end = start;
        while (end < s.size() && s[end] != ' ')
          end++;
        string word = s.substr(start, end - start);
        reverse(word.begin(), word.end());
        result.append(word);
        if (end < s.size())
          result.append(" ");
        start = end;
      }
      reverse(result.begin(), result.end());
      s = result;
    }
};
