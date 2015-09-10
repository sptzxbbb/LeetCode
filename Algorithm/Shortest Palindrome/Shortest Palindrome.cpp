#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    // abbac
    string shortestPalindrome(string s) {
        int size = s.size();
        bool dp[size][size] = {false};
        for (int i = 0; i < size; i++) {
            dp[i][i] = true;
            for (int j = i - 1; j >= 0; j--) {
                if (s[j] == s[i] && j + 1 <= i - 1 && dp[j + 1][i - 1]) {
                    dp[j][i] = true;
                }
            }
        }
        int index = 0;
        for (int i = 0; i < size; i++) {
            if (dp[0][i]) index = i + 1;
        }
        int len = size - index;
        string temp;
        if (len > 0) {
            temp = s.substr(index, len);
            for (int i = 0; i <= (int)temp.size() / 2; i++) {
                swap(temp[i], temp[temp.size() - 1 - i]);
            }
        }
        string res = temp + s;
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution k;
    string s = "aacecaaa";
    cout << k.shortestPalindrome(s) << endl;
    return 0;
}
