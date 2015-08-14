/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool cmp(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
  public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int size = intervals.size();
        vector<Interval> res;
        if (0 == size) {
            return res;
        }
        Interval cur;
        bool store = true;
        for (int i = 0; i < size; i++) {
            if (true == store) {
                cur = intervals[i];
                store = false;
            } else if (false == store &&
                       intervals[i].start >= cur.start &&
                       intervals[i].start <= cur.end) {
                cur.end = max(cur.end, intervals[i].end);
            } else {
                res.push_back(cur);
                store = true;
                --i;
            }
        }
        if (false == store) {
            res.push_back(cur);
        }
        return res;
    }
};
