class Solution {
  public:
    int getFac(int n) {
      int result = 1;
      for (int i = 1; i <= n; i++)
        result *= i;
      return result;
    }
    string getPermutation(int n, int k) {
      vector<bool> used(n + 1, false);
      string result;
      const int size = n;
      while (result.size() < size) {
        int fac = getFac(n - 1);
        int index = 1;
        while (k > fac) {
          k -= fac;
          index++;
        }
        for (int i = 1; i <= size; i++) {
          if (used[i] == false)
            index--;
          if (index == 0) {
            result.append(to_string(i));
            used[i] = true;
            break;
          }
        }
        n--;
      }
      return result;
    }
};
