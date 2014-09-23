//http://www.careercup.com/question?id=15503949

int Celebrity(const vector<vector<int>>& a) {
  int candidate = 0;
  int i = 1;
  while (i < a.size()) {
    if (!a[i][candidate] || a[candidate][i])
      candidate = i;
    i++;
  }
  for (int i = 0; i < a.size(); i++) {
    if (i != candidate && (!a[i][candidate] || a[candidate][i]))
      return -1;
  }
  return candidate;
}
