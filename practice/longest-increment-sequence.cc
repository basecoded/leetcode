// http://qiemengdao.iteye.com/blog/1660229

int BinarySearch(const vector<int>& v, int start, int end, int target) {
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (target < v[mid])
      end = mid - 1;
    else if (target > v[mid])
      start = mid + 1;
    else
      return mid;
  }
  return start;
}

int LongestIncrementSequence(const vector<int>& num) {
  int n = num.size(), len = 1;
  vector<int> end(n + 1);
  end[1] = num[0];
  for (int i = 1; i < n; i++) {
    int pos = BinarySearch(end, 1, len, num[i]);
    end[pos] = num[i];
    if (pos > len)
      len = pos;
  }
  return len;
}


int main() {
  vector<int> v { 2, 1, 5, 3, 6, 4, 8, 9, 7 };
  cout << LongestIncrementSequence(v) << endl;
  return 0;
}
