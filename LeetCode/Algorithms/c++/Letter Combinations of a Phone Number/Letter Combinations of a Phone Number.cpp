class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string ele;
        next(digits, 0, ele, res);
        return res;
    }
    void next(string& digits, int cur, string& ele, vector<string>& res) {
        string mapping[] = {"", "", "abc", "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.size() == 0) {
            return;
        }
        if (cur == digits.size()) {
            res.push_back(ele);
            return;
        }
        int index = digits[cur] - '0';
        if (index < 2) {
            next(digits, cur + 1, ele, res);
        }
        int size = mapping[index].size();
        for (int i = 0; i < size; i++) {
            ele.push_back(mapping[index][i]);
            next(digits, cur + 1, ele, res);
            ele.pop_back();
        }
        return;
    }
};