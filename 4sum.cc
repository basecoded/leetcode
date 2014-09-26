class Solution {
  public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
      vector<vector<int>> result;
      sort(num.begin(), num.end());
      for (int i = 0; i <= (signed)num.size() - 4; i++) {
        if (i > 0 && num[i] == num[i-1])
          continue;
        for (int j = i + 1; j <= (signed)num.size() - 3; j++) {
          if (j > i + 1 && num[j] == num[j-1])
            continue;
          int m = j + 1;
          int n = num.size() - 1;
          while (m < n) {
            int sum = num[i] + num[j] + num[m] + num[n];
            if (sum < target) {
              m++;
            } else if(sum > target) {
              n--;
            } else{
              vector<int> v;
              v.push_back(num[i]);
              v.push_back(num[j]);
              v.push_back(num[m]);
              v.push_back(num[n]);
              result.push_back(v);
              int new_m = m;
              while(new_m < num.size() && num[new_m] == num[m])
                new_m++;
              m = new_m;
            }
          }
        }
      }
      return result;
    }
};
