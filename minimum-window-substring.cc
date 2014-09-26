class Solution {
  public:
    string minWindow(string S, string T) {
      unordered_map<char, int> appeared, expected;
      for (const auto& ch : T)
        expected[ch]++;
      int left = 0, right = 0;
      int min_length = INT_MAX, number = 0, min_start = 0;
      while (right < S.size()) {
        char ch = S[right];
        if (expected.find(ch) != expected.end()) {
          appeared[ch]++;
          if (appeared[ch] <= expected[ch])
            number++;
        }
        if (number == T.size()) {
          while (expected.find(S[left]) == expected.end()
              || appeared[S[left]] > expected[S[left]]) {
            if (expected.find(S[left]) == expected.end())
              ;
            else
              appeared[S[left]]--;
            left++;
          }
          if (min_length > right - left + 1) {
            min_length = right - left + 1;
            min_start = left;
          }
        }
        right++;
      }
      return min_length == INT_MAX ? "" : S.substr(min_start, min_length);
    }
};
