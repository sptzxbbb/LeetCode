class Solution {
public:
    void reverseWords(string &s) {
        // clear spaces
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == ' ') {
                size_t pos = s.find_first_not_of(' ', i);
                s.erase(i, pos - i - (i ? 1 : 0));
            }
        }
        // reverse sentence
        reverse(s, 0, s.size() - 1);
        // reverse word
        for (int i = 0; i < (int)s.size(); i++) {
            size_t pos = s.find(' ', i);
            pos = (pos == string::npos ? s.size() : pos);
            reverse(s, i, pos - 1);
            i = pos;
        }
        return;
    }
    // [from, to]
    void reverse(string& s, int from, int to) {
        for (int i = from; i <= (from + to) / 2 ; i++) {
            swap(s[i], s[to - i + from]);
        }
    }
};