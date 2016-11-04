class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool> qualified(n + 1, false);
        qualified[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) { // can be forward as well
                if (qualified[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                    qualified[i] = true;
                    break;
                }
            }
        }
        return qualified[n];
    }
};
