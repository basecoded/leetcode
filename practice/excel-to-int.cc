int StringToInt(const string& str) {
  int re = 0;
  for (const char ch : str) {
    re = re * 26 + ch - 'A' + 1;
  }
  return re;
}

string IntToString(int num) {
  string str;
  while (num) {
    int d = (num - 1) % 26;
    str.push_back('A' + d);
    num = (num - d - 1) / 26;
  }
  reverse(str.begin(), str.end());
  return str;
}



int main() {
  int num;
  while (cin >> num) {
    string str = IntToString(num);
    cout << str << endl;
    cout << StringToInt(str) << endl;
  }
  return 0;
}
