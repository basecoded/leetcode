class Solution {
  public:
    int maxProfit(vector<int> &prices) {
      int size = prices.size();
      if(size < 2)
        return 0;
      vector<int> f(size, 0);
      vector<int> g(size, 0);
      int min_price = prices[0];
      for(int i = 1; i < size; i++) {
        min_price = min(min_price, prices[i]);
        f[i] = max(f[i - 1], prices[i] - min_price);
      }
      int max_price = prices[size - 1];
      for(int i = size - 2; i >= 0; i--) {
        max_price = max(max_price, prices[i]);
        g[i] = max(g[i + 1], max_price - prices[i]);
      }
      int max_profit = 0;
      for(int i = 0; i < size; i++)
        max_profit = max(max_profit, f[i] + g[i]);
      return max_profit;
    }
};
