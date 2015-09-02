class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }
        //map<char, int> t_Count, s_Count;
        int t_Count[256] = {0}, s_Count[256] = {0};

        int charInT = 0;
        for (int i = 0; i < (int)t.size(); i++) {
            ++t_Count[t[i]];
            if (t_Count[t[i]] == 1) {
                ++charInT;
            }
        }
        int start = 0;
        int charInS = 0;
        int minWin = INT_MAX;
        int minStart = 0, minEnd = 0;
        for (int end = 0; end < (int)s.size(); end++) {
            if (t_Count[s[end]] != 0) {
                ++s_Count[s[end]];
                if (s_Count[s[end]] == t_Count[s[end]]) {
                    ++charInS;
                }
            }
            // a windows is found, try to minimize the start
            while (charInS == charInT) {
                if (end - start + 1 < minWin) {
                    minWin = end - start + 1;
                    minStart = start;
                    minEnd = end;
                }
                if (t_Count[s[start]] != 0) {
                    --s_Count[s[start]];
                    if (s_Count[s[start]] < t_Count[s[start]]) {
                        --charInS;
                    }
                }
                ++start;
            }
        }
        if (minWin == INT_MAX) {
            return "";
        } else {
            return s.substr(minStart, minEnd - minStart + 1);
        }
    }
};