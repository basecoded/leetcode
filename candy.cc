class Solution {
  public:
    int candy(vector<int> &ratings) {
      int size = ratings.size();
      vector<int> candy(size, 1);
      for(int i = 0; i < size - 1; i++) {
        if(ratings[i+1] > ratings[i])
          candy[i+1] = max(candy[i+1], candy[i] + 1);
      }
      for(int i = size - 1; i > 0; i--) {
        if(ratings[i-1] > ratings[i])
          candy[i-1] = max(candy[i-1], candy[i] + 1);
      }
      int sum = 0;
      for(auto c : candy)
        sum += c;
      return sum;
    }
};
