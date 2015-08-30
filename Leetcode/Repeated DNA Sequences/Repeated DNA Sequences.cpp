class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() <= 10) {
            return res;
        }
        int mask = 0x7ffffff;
        unordered_map<int, int> m;
        int cur = 0, i = 0;
        while (i < 9) {
            cur = (cur << 3) | (s[i++] & 7);
        }
        while (i < s.size()) {
            cur = ((cur & mask) << 3) | (s[i++] & 7);
            if (m.find(cur) != m.end()) {
                if (m[cur] == 1) {
                    res.push_back(s.substr(i - 10, 10));
                }
                ++m[cur];
            } else {
                m[cur] = 1;
            }
        }
        return res;
    }
};