class Solution {
  public:
    int findMin(vector<int> &num) {
      return FindMinHelper(num, 0, num.size() - 1);
    }

    int FindMinHelper(const vector<int>& num, int start, int end) {
      if (start == end)
        return num[start];
      int mid = start + (end - start) / 2;
      if (num[mid] > num[end]) {
        return FindMinHelper(num, mid + 1, end);
      } else if (num[mid] < num[end]) {
        return FindMinHelper(num, start, mid);
      } else {
        int l_res = FindMinHelper(num, start, mid);
        int r_res = FindMinHelper(num, mid + 1, end);
        return min(l_res, r_res);
      }
    }
};
