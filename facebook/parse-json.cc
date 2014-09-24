#include <iostream>
#include <string>

using namespace std;

void PrintIndent(int indent) {
  while (indent--)
    cout << "  ";
  return;
}

void ParseJson(const string& str) {
  int indent = 0, start = 3;
  while (start < str.size()) {
    int end = str.find("'", start);
    string key = str.substr(start, end - start);
    PrintIndent(indent);
    cout << key << ":";
    start = end + 1;
    if (str[start + 1] == '\'') {
      start += 2;
      end = str.find("'", start);
      cout << str.substr(start, end - start) << endl;
      if (str[end + 1] == ']') {
        PrintIndent(indent);
        cout << "]" << endl;
        indent--;
        end++;
      }
      start = end + 3;
    } else { // '['
      cout << "[" << endl;
      indent++;
      start += 3;
    }
  }
}

int main() {
  string str = "\"{'a':'1','b':['c':'2','d':'3']}\"";
  ParseJson(str);
  return 0;
}
