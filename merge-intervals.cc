/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool comp(const Interval& interval1, const Interval& interval2) {
  return interval1.start < interval2.start;
}

class Solution {
  public:
    vector<Interval> merge(vector<Interval> &intervals) {
      vector<Interval> result;
      if (intervals.size() == 0)
        return result;
      sort(intervals.begin(), intervals.end(), comp);
      Interval curr = intervals[0];
      for (int i = 1; i < intervals.size(); i++) {
        if (curr.end >= intervals[i].start) {
          curr.end = max(curr.end, intervals[i].end);
        } else {
          result.push_back(curr);
          curr = intervals[i];
        }
      }
      result.push_back(curr); 
      return result;
    }
};
