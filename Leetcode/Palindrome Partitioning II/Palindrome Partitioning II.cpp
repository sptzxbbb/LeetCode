class Solution {
public:
    int minCut(string s) {
        int size = s.size();

        bool p[size][size] = {false};
        // D[i] = 区间[i, n]之间最小的cut数, n为字符串长度.
        int D[size + 1];
        for (int i = 0; i <= size; i++) {
            D[i] = size - i;
        }
        for (int i = size - 1; i >= 0; --i) {
            for (int j = i; j < size; ++j) {
                if (s[i] == s[j] && (i == j + 1 || p[i + 1][j - 1])) {
                    p[i][j] = true;
                    D[i] = min(D[i], 1 + D[j + 1]);
                }
            }
        }
        return D[0] - 1;
    }
};