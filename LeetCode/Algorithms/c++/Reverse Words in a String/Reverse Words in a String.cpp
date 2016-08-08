class Solution {
public:
    void reverseWords(string &s) {
        stack<string> t;
        int index = 0, size = s.size();
        string temp = "";
        while (index < size) {
            if (s[index] != ' ') {
                temp += s[index];
            } else {
                if (!temp.empty()) {
                    t.push(temp);
                    temp.clear();
                }
            }
            ++index;
        }
        if (!temp.empty()) {
            t.push(temp);
            temp.clear();
        }
        string res;
        while (!t.empty()) {
            res += t.top() + " ";
            t.pop();
        }
        if (!res.empty()) res.pop_back();
        s = res;
    }
};