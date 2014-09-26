struct Element {
  int val;
  int index;
};
bool comp(Element ele1, Element ele2) {
  return ele1.val < ele2.val;
}
class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
      int size = numbers.size();
      Element elements[size];
      for(int i = 0; i < size; i++)
        elements[i] = Element{numbers[i], i + 1};
      sort(elements, elements + size, comp);
      int left = 0;
      int right = size - 1;
      while(left < right) {
        int sum = elements[left].val + elements[right].val;
        if(sum < target) {
          left++;
        } else if(sum > target) {
          right--;
        } else {
          vector<int> v;
          v.push_back(elements[left].index);
          v.push_back(elements[right].index);
          if(v[0] > v[1])
            swap(v[0], v[1]);
          return v;
        }
      }
      return vector<int>(2, -1);
    }
};
