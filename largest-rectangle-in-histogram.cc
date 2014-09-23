class Solution {
  public:
    int largestRectangleArea(vector<int> &height) {
      int max_area = 0;
      stack<int> stk;
      height.push_back(0);
      for (int i = 0; i < height.size();) {
        if (stk.empty() || height[i] > height[stk.top()]) {
          stk.push(i++);
        } else {
          int idx = stk.top();
          stk.pop();
          int area = height[idx] * (stk.empty() ? i : i - stk.top() - 1);
          max_area = max(max_area, area);
        }
      }
      return max_area;
    }
};
