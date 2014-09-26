class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int left = 0, right = 0, length = 0;
      unordered_map<char, int> appeared;
      while (right < s.size()) {
        if (appeared[s[right]] == 0) {
          appeared[s[right]] = 1;
          right++;
        } else {
          length = max(length, right - left);
          while (appeared[s[right]] == 1) {
            appeared[s[left]] = 0;
            left++;
          }
        }
      }
      length = max(length, right - left);
      return length;
    }
};
