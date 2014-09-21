class Solution {
  public:
    int maxProfit(vector<int> &prices) {
      if (prices.size() < 2)
        return 0;
      int profit = 0;
      int low_price = prices[0];
      for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > low_price)
          profit = max(profit, prices[i] - low_price);
        low_price = min(low_price, prices[i]);
      }
      return profit;
    }
};
