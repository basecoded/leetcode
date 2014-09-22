class Solution {
  public:
    void nextPermutation(vector<int> &num) {
      int left = -1, right = -1;
      int i = num.size() - 2;
      for (; i >= 0; i--) {
        if (num[i] < num[i+1]) {
          left = i;
          break;
        }
      }
      if (left == -1) {
        reverse(num.begin(), num.end());
        return;
      }
      i = num.size() - 1;
      for (;i >= 0; i--) {
        if (num[i] > num[left]) {
          right = i;
          break;
        }
      }
      swap(num[left], num[right]);
      left++;
      i = num.size() - 1;
      while (left < i) {
        swap(num[left++], num[i--]);
      }
      return;
    }
};
