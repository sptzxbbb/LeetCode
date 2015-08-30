#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = 1;
        int start = 0;
        int left = 0, right = 0;
        int size = s.size();
        for (int i = 0; i < size - 1; i++) {
            if (s[i] == s[i + 1]) {
                left = i;
                right = i + 1;
                search(s, left, right, len, start);
            }
            left = i;
            right = i;
            search(s, left, right, len, start);
        }
        return s.substr(start, len);
    }
    void search(string& s, int left, int right, int& len, int& start) {
        int step = 0;
        while ((left - step >= 0) && (right + step < (int)s.size())) {
            if (s[left - step] != s[right + step]) {
                --step;
                break;
            }
            ++step;
        }
        if (right + step >= (int)s.size() || left - step < 0) {
            --step;
        }

        int width = (right - left + 1) + 2 * step;
        if (width > len) {
            len = width;
            start = left - step;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution k;
    cout << k.longestPalindrome("abb") << endl;
    return 0;
}

