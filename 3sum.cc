class Solution {
  public:
    vector<vector<int> > threeSum(vector<int> &num) {
      vector<vector<int>> result;
      sort(num.begin(), num.end());
      for(int i = 0; i <= (signed)num.size() - 3; i++) {
        if(i > 0 && num[i] == num[i-1])
          continue;
        int j = i + 1;
        int k = num.size() - 1;
        while(j < k) {
          int sum = num[i] + num[j] + num[k];
          if(sum < 0)
            j++;
          else if(sum > 0)
            k--;
          else {
            vector<int> v;
            v.push_back(num[i]);
            v.push_back(num[j]);
            v.push_back(num[k]);
            result.push_back(v);
            int new_j = j;
            while(new_j < num.size() && num[new_j] == num[j])
              new_j++;
            j = new_j;
          }
        }
      }
      return result;
    }
};
