class Solution {
  public:
    int longestConsecutive(vector<int> &num) {
      unordered_map<int, bool> used;
      for (const auto a : num)
        used[a] = false;
      int longest = 0;
      for (const auto a : num) {
        if (used[a])
          continue;
        used[a] = true;
        int val = a + 1;
        int number = 1;
        while (used.find(val) != used.end() && used[val] == false) {
          used[val] = true;
          val++;
          number++;
        }
        val = a - 1;
        while (used.find(val) != used.end() && used[val] == false) {
          used[val] = true;
          val--;
          number++;
        }
        longest = max(longest, number);
      }
      return longest;
    }
};
