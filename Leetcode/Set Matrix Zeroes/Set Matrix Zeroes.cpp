class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroRow = false, zeroCol = false;
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < col; i++) {
            if (0 == matrix[0][i]) {
                zeroRow = true;
                break;
            }
        }
        for (int i = 0; i < row; i++) {
            if (0 == matrix[i][0]) {
                zeroCol = true;
                break;
            }
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (0 == matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (0 == matrix[i][0] || 0 == matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (zeroRow) {
            for (int i = 0; i < col; i++) {
                matrix[0][i] = 0;
            }
        }
        if (zeroCol) {
            for (int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
        return;
    }
};
