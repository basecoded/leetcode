class Solution {
  public:
    int sqrt(int x) {
      if (x < 0)
        return -1;
      if (x == 0 || x == 1)
        return x;
      int start = 0, end = x;
      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mid < x / mid)
          start = mid + 1;
        else if (mid > x / mid)
          end = mid - 1;
        else
          return mid;
      }
      return end;
    }
};
