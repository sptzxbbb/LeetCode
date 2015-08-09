class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        if (s1.size() != s2.size()) {
            return false;
        }
        int letter[26];
        memset(letter, 0, sizeof(letter));
        int size = s1.size();
        for (int i = 0; i < size; i++) {
            ++letter[s1[i] - 'a'];
            --letter[s2[i] - 'a'];
        }
        for (int i = 0; i < 26; i++) {
            if (letter[i] != 0) {
                return false;
            }
        }
        for (int i = 1; i < size; i++) {
            bool result;
            result = isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                    isScramble(s1.substr(i), s2.substr(i));
            result = result || (isScramble(s1.substr(0, i), s2.substr(size - i)) &&
                                isScramble(s1.substr(i), s2.substr(0, size - i)));
            if (result) {
                return true;
            }
        }
        return false;
    }
};