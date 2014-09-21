class Solution {
  public:
    int singleNumber(int A[], int n) {
      vector<int> bit(32, 0);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < 32; j++) {
          if ((A[i] >> j) & 1)
            bit[j]++;
        }
      }
      int result = 0;
      for (int i = 0; i < 32; i++) {
        if (bit[i] % 3)
          result += (1 << i);
      }
      return result;
    }
};
