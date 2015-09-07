// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long ans;
        binary(1, n, ans);
        return ans;
    }
    void binary(long start, long end, long& ans) {
        if (start > end) {
            return;
        }
        long mid = (start + end) / 2;
        if (isBadVersion(mid)) {
            ans = min(ans, mid);
            binary(start, mid - 1, ans);
        } else {
            binary(mid + 1, end, ans);
        }
        return;
    }
};