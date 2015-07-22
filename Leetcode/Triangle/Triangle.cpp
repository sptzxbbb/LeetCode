class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        vector<int> ans;
        int row = triangle.size();
        int col = triangle[row - 1].size();
        // initialize
        for (int i = 0; i < col; i++) {
            ans.push_back(triangle[row - 1][i]);
        }
        for (int i = row - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                ans[j] = min(ans[j], ans[j + 1]) + triangle[i][j];
            }
        }
        return ans[0];
    }
};