class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
      int start = -1;
      int total = 0, total_cost = 0, sum = 0;
      for (int i = 0; i < gas.size(); i++) {
        sum += (gas[i] - cost[i]);
        total += gas[i];
        total_cost += cost[i];
        if (sum < 0) {
          start = i;
          sum = 0;
        }
      }
      return total >= total_cost ? start + 1 : -1;
    }
};
