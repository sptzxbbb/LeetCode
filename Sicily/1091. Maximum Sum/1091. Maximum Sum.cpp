#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int sum(vector<int>& v) {
        vector<int> l(v.size()), r(v.size());
        vector<int> sumL(v.size()), sumR(v.size());
        vector<bool> take(v.size());
        int maxSum = INT_MIN, index = 0;
        // from left to right
        l[0] = v[0];
        sumL[0] = l[0];
        maxSum = l[0];
        take[0] = true;
        for (int i = 1; i < (int)v.size(); i++) {
            if (l[i - 1] <= 0) {
                l[i] = v[i];
            } else {
                l[i] = l[i - 1] + v[i] >= 0 ? l[i - 1] + v[i] : v[i];
            }
            if (maxSum < l[i]) {
                maxSum = l[i];
                index = i;
            }
            sumL[i] = maxSum;
            take[i] = (i == index);
        }
        // fromt right to left
        r[v.size() - 1] = v[v.size() - 1];
        sumR[v.size() - 1] = r[v.size() - 1];
        maxSum = r[v.size() - 1];
        for (int i = (int)v.size() - 2; i >= 0; --i) {
            if (r[i + 1] <= 0) {
                r[i] = v[i];
            } else {
                r[i] = r[i + 1] + v[i] >= 0 ? r[i + 1] + v[i] : v[i];
            }
            maxSum = max(maxSum, r[i]);
            sumR[i] = maxSum;
        }
        // calculate maxSum
        maxSum = INT_MIN;
        for (int i = 0; i < (int)v.size() - 1; i++) {
            if (take[i]) {
                maxSum = max(maxSum, sumL[i] + sumR[i + 1]);
            } else {
                maxSum = max(maxSum, sumL[i] + sumR[i]);
            }
        }
        return maxSum;
    }
};

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        vector<int> v(k, 0);
        for (int i = 0; i < k; i++) {
            cin >> v[i];
        }
        Solution q;
        cout << q.sum(v) << endl;
    }
    return 0;
}
