/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
  public:
    int maxPoints(vector<Point> &points) {
      int max_point = 0;
      for (int i = 0; i < points.size(); i++) {
        int vertical = 0;
        int same = 0;
        unordered_map<float, int> k;
        for (int j = 0; j < points.size(); j++) {
          if (points[i].x == points[j].x && points[i].y == points[j].y)
            same++;
          else if (points[i].x == points[j].x)
            vertical++;
          else 
            k[float(points[i].y - points[j].y) / (points[i].x - points[j].x)]++;
        }
        int k_max = 0;
        for (auto const& pair : k)
          k_max = max(k_max, pair.second);
        max_point = max(max_point, max(vertical, k_max) + same);
      }
      return max_point;
    }
};
