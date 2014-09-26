class Solution {
  public:
    vector<string> anagrams(vector<string> &strs) {
      unordered_map<string, vector<string>> m;
      for(const auto s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        m[key].push_back(s);
      }

      vector<string> result;
      for(const auto p : m) {
        if(p.second.size() > 1) {
          result.insert(result.end(), p.second.begin(), p.second.end());
        }
      }
      return result;
    }
};
