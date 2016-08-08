class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        vector<pair<int, int> > height;
        for (auto &e : buildings) {
            height.push_back({e[0], -e[2]});
            height.push_back({e[1], e[2]});
        }
        sort(height.begin(), height.end());
        multiset<int> heap;
        heap.insert(0);
        vector<pair<int, int> > res;
        int pre = 0, cur = 0;
        for (auto &h : height) {
            if (h.second < 0) {
                heap.insert(-h.second);
            } else {
                heap.erase(heap.find(h.second));
            }
            // the highest building
            cur = *heap.rbegin();
            if (cur != pre) {
                res.push_back({h.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};