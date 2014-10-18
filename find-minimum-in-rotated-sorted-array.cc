class Solution {
  public:
    int findMin(vector<int> &num) {
      int l = 0, r = num.size() - 1;
      while (l < r) {
        int m = l + (r - l) / 2;
        if (num[m] > num[r])
          l = m + 1;
        else
          r = m;
      }
      return num[l];
    }
};
