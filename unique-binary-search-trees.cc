class Solution {
  public:
    int numTrees(int n) {
      if (n < 3)
        return n;
      vector<int> trees(n + 1, 0);
      trees[0] = 1;
      trees[1] = 1;
      trees[2] = 2;
      for (int i = 3; i <= n; i++) {
        for (int k = 0; k < i; k++)
          trees[i] += trees[k] * trees[i - k - 1];
      }
      return trees[n];
    }
};
