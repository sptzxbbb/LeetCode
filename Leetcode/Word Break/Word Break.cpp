class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        string s2 = '#' + s;
        int size = s2.size();
        vector<bool> possible(size, false);
        possible[0] = true;
        for (int i = 1; i < size; i++) {
            for (int k = 0; k < i; k++) {
                possible[i] = possible[k] &&
                        wordDict.find(s2.substr(k + 1, i - k)) != wordDict.end();
                if (possible[i]) {
                    break;
                }
            }
        }
        return possible[size - 1];
    }
};