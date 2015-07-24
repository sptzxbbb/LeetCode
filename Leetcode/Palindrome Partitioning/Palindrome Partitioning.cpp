class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > ans;
        vector<string> ele;
        dfs(s, 0, ele, ans);
        return ans;
    }

    void dfs(string& s, int start, vector<string>& ele, vector<vector<string> > & ans) {
        if (start == s.size()) {
            ans.push_back(ele);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                ele.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, ele, ans);
                ele.pop_back();
            }
        }
        return;
    }

    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};