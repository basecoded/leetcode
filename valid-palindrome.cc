class Solution {
  public:
    bool isPalindrome(string s) {
      if (s.size() == 0)
        return true;
      int left = 0, right = s.size() - 1;
      while (left < right) {
        while (left < s.size() && !isalnum(s[left]))
          left++;
        while (right >= 0 && !isalnum(s[right]))
          right--;
        if (left < right && tolower(s[left]) != tolower(s[right]))
          return false;
        left++;
        right--;
      }
      return true;
    }
};
