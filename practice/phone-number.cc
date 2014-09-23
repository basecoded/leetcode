#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<string> keyboard {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void dfs(vector<string>& result, string& tmp, int start, const string& str) {
  if (start == str.size()) {
    result.push_back(tmp);
    return;
  }
  if (start > 0 && str[start] == str[start - 1]) {
    tmp.push_back(tmp[tmp.size() - 1]);
    dfs(result, tmp, start + 1, str);
    tmp.pop_back();
  } else {
    string letters = keyboard[str[start] - '0'];
    for (int i = 0; i < letters.size(); i++) {
      tmp.push_back(letters[i]);
      dfs(result, tmp, start + 1, str);
      tmp.pop_back();
    }
  }
}

vector<string> PhoneCombination(const string& str) {
  vector<string> result;
  string tmp;
  dfs(result, tmp, 0, str);
  return result;
}

int main() {
  string digits = "112";
  vector<string> result = PhoneCombination(digits);
  for (const auto s : result)
    cout << s << endl;
  return 0;
}
