class Solution {
  public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
      queue<string> current, next;
      unordered_map<string, bool> used;
      for (const auto& word : dict)
        used[word] = false;
      int step = 1;
      current.push(start);
      while (!current.empty()) {
        step++;
        while (!current.empty()) {
          string word = current.front();
          current.pop();
          for (int i = 0; i < word.size(); i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
              if (ch == word[i])
                continue;
              swap(ch, word[i]);
              if (word == end)
                return step;
              if (dict.find(word) != dict.end() && used[word] == false) {
                next.push(word);
                used[word] = true;
              }
              swap(ch, word[i]);
            }
          }
        }
        swap(current, next);
      }
      return 0;
    }
};
