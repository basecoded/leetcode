class Solution {
  public:
    int threeSumClosest(vector<int> &num, int target) {
      sort(num.begin(), num.end());
      int gap = INT_MAX, sum = 0;
      for (int i = 0; i < num.size() - 2; i++) {
        int left = i + 1, right = num.size() - 1;
        while (left < right) {
          int tmp = num[i] + num[left] + num[right];
          if (abs(target - tmp) < gap) {
            gap = abs(target - tmp);
            sum = tmp;
          }
          if (tmp < target)
            left++;
          else if (tmp > target)
            right--;
          else
            return target;
        }
      }
      return sum;
    }
};
