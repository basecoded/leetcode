class Solution {
  public:
    vector<int> findSubstring(string S, vector<string> &L) {
      vector<int> result;
      if (L.empty())
        return result;
      int each_len = L[0].size();
      int total_len = L.size() * each_len;
      if(S.size() < total_len)
        return result;
      unordered_map<string, int> words;
      for (auto word : L)
        words[word]++;
      for (int i = 0; i <= S.size() - total_len; i++) {
        unordered_map<string, int> left(words);
        for(int j = i; j < S.size(); j+=each_len) {
          string word = S.substr(j, each_len);
          if(left.find(word) != left.end()) {
            if(--left[word] == 0) {
              left.erase(word);
              if(left.size() == 0) {
                result.push_back(i);
                break;
              }
            }
          } else {
            break;
          }
        }
      }
      return result;
    }
};
