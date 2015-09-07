class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int left = 0, right = 0;
        string s = "";
        ans.clear();
        generate(s, 0, 0, n);
        return ans;
    }

    void generate(string& s, int left, int right, int n) {
        if ((left + right) == 2 * n) {
            ans.push_back(s);
            return;
        }
        if (left < n) {
            s += '(';
            generate(s, left + 1, right, n);
            s.pop_back();
        }
        if (right < left) {
            s += ')';
            generate(s, left, right + 1, n);
            s.pop_back();
        }
        return;
    }
private:
    vector<string> ans;
};

