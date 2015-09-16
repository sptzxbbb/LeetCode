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
    int maxPoints(vector<Point>& points) {
        int size = points.size();
        if (size == 0) {
            return 0;
        }
        int res = 0;
        int duplicate = 0;
        map<double, int> t;
        for (int i = 0; i < size; i++) {
            t.clear();
            duplicate = 1;
            for (int j = 0; j < size; j++) {
                if (i == j) continue;
                double k = 0.0;
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++duplicate;
                    continue;
                } else if (points[i].x == points[j].x) {
                    k = INT_MAX;
                } else {
                    k = (double)(points[i].y - points[j].y) / (double)(points[i].x - points[j].x);
                }
                t[k]++;
            }
            res = max(res, duplicate);
            for (auto e = t.begin(); e != t.end(); ++e) {
                res = max(res, e->second + duplicate);
            }
        }
        return res;
    }
};