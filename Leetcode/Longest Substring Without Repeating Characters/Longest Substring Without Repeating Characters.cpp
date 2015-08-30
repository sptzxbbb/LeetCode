class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size(), len = 0;
        vector<int> table(256, -1);
        int start = 0;
        for (int i = 0; i < size; i++) {
            if (table[s[i]] != -1) {
                while (start <= table[s[i]]) {
                    table[s[start++]] = -1;
                }
            }
            if (i - start + 1 > len) {
                len = i - start + 1;
            }
            table[s[i]] = i;
        }
        return len;
    }
};