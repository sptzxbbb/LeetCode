class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> digit(n);
        int count = 1;
        for (int i = 0; i < n; i++) {
            digit[i] = i + 1;
            count *= digit[i];
        }
        // change k from (1, n) to (0, n - 1) to accord to index
        --k;
        int position;
        string ans = "";
        for (int i = 0; i < n; i++) {
            count /= (n - i);
            position = k / count;
            ans.push_back(digit[position] + '0');
            k %= count;
            digit.erase(digit.begin() + position);
        }
        return ans;
    }
};
