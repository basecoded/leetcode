#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(vector<string>& result, string tmp, int start, const string& str) {
  if (start == str.size()) {
    result.push_back(tmp);
    return;
  }
  if (str[start] != 0) {
    dfs(result, tmp + (char)(str[start] - '1' + 'a'), start + 1, str);
  }
  if (start + 1 < str.size()
      && (str[start] == '1' ||
          (str[start] == '2' && str[start+1] >= '0' && str[start+1] <= '6'))) {
    int offset = (str[start] - '0') * 10 + str[start + 1] - '0';
    dfs(result, tmp + (char)(offset - 1 + 'a'), start + 2, str);
  }
}

vector<string> DecodeWays(const string& str) {
  vector<string> result;
  string tmp;
  dfs(result, tmp, 0, str);
  return result;
}

int main() {
  vector<string> result = DecodeWays("1123");
  for (const auto v : result)
    cout << v << endl;
  return 0;
}
