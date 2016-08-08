class Solution {
public:
    // sort
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ans = 0;
        int n = citations.size();
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= n) {
                ans = n;
                break;
            }
            --n;
        }
        return ans;
    }
};


class Solution {
public:
    // use extra space
    int hIndex(vector<int>& citations) {
        int cnt[citations.size()], sum = 0, ans = 0;
        fill(cnt, cnt + citations.size(), 0);
        for (auto &v : citations) {
            if (v < citations.size()) {
                cnt[v]++;
            }
        }
        for (int i = 0; i < citations.size(); i++) {
            sum += cnt[i];
            if (citations.size() - sum >= i+1) {
                 ans = max(i + 1, ans);
            }
        }
        return ans;
    }
};
