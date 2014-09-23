class Solution {
  public:
    string simplifyPath(string path) {
      vector<string> tokens;
      int start = 0;
      while (start < path.size()) {
        int end = path.find("/", start);
        if (start == end) {
          start++;
          continue;
        } else if (end == string::npos) {
          end = path.size();
        }
        string tmp = path.substr(start, end - start);
        start = end + 1;
        if (tmp == ".") {
          continue;
        } else if (tmp == "..") {
          if (tokens.size() > 0)
            tokens.pop_back();
        } else {
          tokens.push_back(tmp);
        }
      }
      string result;
      for (const auto t : tokens)
        result += ("/" + t);
      if (result.size() == 0)
        return "/";
      else
        return result;
    }
};
